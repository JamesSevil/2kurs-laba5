#include "processingreq.h"

string processingReq(string& zaprosClient, vector<PeripheralDevice*> devices) {
    string result;
    if (zaprosClient == "all") {
        result = selectall(devices);
    } else if (zaprosClient == "selectheadphones") {
        result = selectdevice("headphones", devices);
    } else if (zaprosClient == "selectmicrophone") {
        result = selectdevice("microphone", devices);
    } else if (zaprosClient == "selectkeyboard") {
        result = selectdevice("keyboard", devices);
    } else {
        result = "error zapros";
    }
    return result;
}

string selectall(vector<PeripheralDevice*> devices) {
    string result;
    for (auto device : devices) {
        result += device->getInfo() + "\n";
    }
    return result;
}

string selectdevice(string choice, vector<PeripheralDevice*> devices) {
    string result;
    for (auto device : devices) {
        if ((choice == "headphones" && dynamic_cast<Headphones*>(device)) ||
            (choice == "microphone" && dynamic_cast<Microphone*>(device)) ||
            (choice == "keyboard" && dynamic_cast<Keyboard*>(device))) {

            result += device->getInfo() + "\n";
        }
    }
    return result;
}
