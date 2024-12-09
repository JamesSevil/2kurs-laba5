#include <iostream>
#include <vector>
#include <string>
#include "network.h"

using namespace std;

int main() {
    vector<PeripheralDevice*> devices; // список устройств
    devices.push_back(PeripheralFactory::createDevice("headphones", {"001", "BrandA", "1000", "over-ear", "wired"}));
    devices.push_back(PeripheralFactory::createDevice("microphone", {"002", "BrandB", "1500", "20Hz-20kHz", "high"}));
    devices.push_back(PeripheralFactory::createDevice("keyboard", {"003", "BrandC", "2000", "mechanical", "USB"}));

    NetWork network(devices);
    network.createSocketAndConnect();

    for (auto device : devices) {
        delete device;
    }

    return 0;
}
