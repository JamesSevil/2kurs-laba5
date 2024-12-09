#ifndef PERIPHERAL_H
#define PERIPHERAL_H

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Базовый класс для периферийного устройства
class PeripheralDevice {
protected:
    string itemNumber; // номенклатурный номер
    string brand; // бренд
    double price; // цена
public:
    PeripheralDevice(const string& itemNumber, const string& brand, double price);
    virtual ~PeripheralDevice();
    virtual string getInfo() const = 0; // Чисто виртуальная функция
};

// Конкретный класс для наушников
class Headphones : public PeripheralDevice {
private:
    string constructionType; // тип конструкции
    string mountingMethod; // метод крепления
public:
    Headphones(const string& itemNumber, const string& brand, double price, const string& constructionType, const string& mountingMethod);
    string getInfo() const override;
};

// Конкретный класс для микрофонов
class Microphone : public PeripheralDevice {
private:
    string frequencyRange; // частотный диапазон
    string sensitivity; // чувствительность
public:
    Microphone(const string& itemNumber, const string& brand, double price, const string& frequencyRange, const string& sensitivity);
    string getInfo() const override;
};

// Конкретный класс для клавиатур
class Keyboard : public PeripheralDevice {
private:
    string switchType; // тип выключателя
    string interfaceType; // интерфейс
public:
    Keyboard(const string& itemNumber, const string& brand, double price, const string& switchType, const string& interfaceType);
    string getInfo() const override;
};

// Фабрика для создания устройств
class PeripheralFactory {
public:
    static PeripheralDevice* createDevice(const string& deviceType, const vector<string>& params);
};

#endif // PERIPHERAL_H
