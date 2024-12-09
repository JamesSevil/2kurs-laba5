#ifndef PROCESSINGREQ_H
#define PROCESSINGREQ_H

#include <string>
#include "peripheral.h"

using namespace std;

string processingReq(string& zaprosClient, vector<PeripheralDevice*> devices);
string selectall(vector<PeripheralDevice*> devices);
string selectdevice(string choice, vector<PeripheralDevice*> devices);


#endif // PROCESSINGREQ_H
