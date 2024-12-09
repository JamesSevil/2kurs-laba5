#include "network.h"

QString NetWork::createSocketAndConnect() {

    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0) {
        return "error socket";
    }

    server_address.sin_port = htons(PORT); // преобразование порта в сетевой порядок байт
    server_address.sin_family = AF_INET; // семейство адресов (IPv 4)

    // Преобразование адреса IPv4 из текстового представления в двоичное
    if (inet_pton(AF_INET, IP.c_str(), &server_address.sin_addr) <= 0) {
        return "error IP";
    }

    if ((::connect(client, (struct sockaddr*)&server_address, sizeof(server_address))) < 0) {
        return "error connect server";
    }

    return "socket create";
}

QString NetWork::sendAndAccept(string& message) {
    send(client, message.c_str(), message.size(), 0);
    char buffer[1024] = {0};
    int check = read(client, buffer, 1024);
    if (check <= 0) { // если сервер отключился
        return "error server kill connection";
    }
    QString result(buffer);
    return result;
}
