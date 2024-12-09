#include "peripheral.h"

// Реализация базового класса PeripheralDevice
PeripheralDevice::PeripheralDevice(const string& itemNumber, const string& brand, double price)
: itemNumber(itemNumber), brand(brand), price(price) {}

PeripheralDevice::~PeripheralDevice() {}


// Реализация класса Headphones
Headphones::Headphones(const string& itemNumber, const string& brand, double price, const string& constructionType, const string& mountingMethod) :
    PeripheralDevice(itemNumber, brand, price), constructionType(constructionType), mountingMethod(mountingMethod) {}

string Headphones::getInfo() const {
    return "Наушники " + brand + " " + itemNumber + " " + to_string(price) + " Конструкция:" + constructionType + " Крепление:" + mountingMethod;
}


// Реализация класса Microphone
Microphone::Microphone(const string& itemNumber, const string& brand, double price, const string& frequencyRange, const string& sensitivity) :
    PeripheralDevice(itemNumber, brand, price), frequencyRange(frequencyRange), sensitivity(sensitivity) {}

string Microphone::getInfo() const {
    return "Микрофон " + brand + " " + itemNumber + " " + to_string(price) + " Част.диапазон:" + frequencyRange + " Чувствительность:" + sensitivity;
}


// Реализация класса Keyboard
Keyboard::Keyboard(const string& itemNumber, const string& brand, double price, const string& switchType, const string& interfaceType) :
    PeripheralDevice(itemNumber, brand, price), switchType(switchType), interfaceType(interfaceType) {}

string Keyboard::getInfo() const {
    return "Клавиатура " + brand + " " + itemNumber + " " + to_string(price) + " Выключатель:" + switchType + " Интерфейс:" + interfaceType;
}


// Реализация фабрики PeripheralFactory
PeripheralDevice* PeripheralFactory::createDevice(const string& deviceType, const vector<string>& params) {
    if (deviceType == "headphones") {
        return new Headphones(params[0], params[1], stod(params[2]), params[3], params[4]);
    } else if (deviceType == "microphone") {
        return new Microphone(params[0], params[1], stod(params[2]), params[3], params[4]);
    } else if (deviceType == "keyboard") {
        return new Keyboard(params[0], params[1], stod(params[2]), params[3], params[4]);
    } else {
        throw invalid_argument("Unknown device type");
    }
}
