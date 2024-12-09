#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QString>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>

using namespace std;

class NetWork {
public:
    QString createSocketAndConnect();
    QString sendAndAccept(string& message);
private:
    int client = -1;
    struct sockaddr_in server_address;
    string IP = "127.0.0.1";
    int PORT = 7432;
};

#endif // NETWORK_H
