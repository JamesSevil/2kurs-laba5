#include "network.h"

NetWork::NetWork(vector<PeripheralDevice*>& devices) {
    this->devices = devices;
}

void NetWork::createSocketAndConnect() {
    server = socket(AF_INET, SOCK_STREAM, 0);
    if (server < 0) {
        cout << "Ошибка создания сокета!" << endl;
        exit(-1);
    }

    if (setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        cout << "Ошибка установки опции сокета" << endl;
        exit(-1);
    }

    server_address.sin_port = htons(PORT); // преобразование порта в сетевой порядок байт
    server_address.sin_family = AF_INET; // семейство адресов (IPv 4)
    server_address.sin_addr.s_addr = INADDR_ANY; // привязка к любому адресу

    if ((bind(server, (struct sockaddr*)&server_address, sizeof(server_address))) < 0) {
        cout << "Ошибка привязки сокета!" << endl;
        exit(-1);
    }

    if (listen(server, 1) < 0) {
        cout << "Ошибка прослушивания!" << endl;
        exit(-1);
    }

    while (true) {
        new_socket = accept(server, (struct sockaddr*)&server_address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            cout << "Ошибка принятия соединения!" << endl;
            exit(-1);
        }
        cout << "Клиент подключен" << endl;

        static mutex mx;
        thread(&NetWork::procOfReq, this, new_socket, ref(mx)).detach();
    }
}

void NetWork::procOfReq(int client_socket, mutex& mx) {
    while (true) {
        char buffer[1024] = {0};
        int check = read(client_socket, buffer, 1024);
        if (check <= 0 ) { // клиент отключился
            cout << "Клиент отключился, ожидание нового подключения..." << endl;
            break;
        }
        string conditions(buffer);
        lock_guard<mutex> lock(mx);
        string message = processingReq(conditions, devices);
        send(client_socket, message.c_str(), message.size(), 0);
    }
    close(client_socket);
}
