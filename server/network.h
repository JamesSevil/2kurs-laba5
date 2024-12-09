#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <arpa/inet.h>
#include "peripheral.h"
#include "processingreq.h"

using namespace std;

#define PORT 7432

class NetWork
{
public:
    NetWork(vector<PeripheralDevice*>& devices);
    void createSocketAndConnect();
    void procOfReq(int client_socket, mutex& mx);
private:
    int server, new_socket; // идентификатор сокетов сервера и нового(для взаимодействия)
    struct sockaddr_in server_address; // информация о адресе сервера
    int addrlen = sizeof(server_address);
    int opt = 1; // переменная для настройки сокета
    vector<PeripheralDevice*> devices;
};

#endif // NETWORK_H
