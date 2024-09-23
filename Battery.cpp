// Battery.cpp
#include "Battery.h"
#include <iostream>

// Constructors
Battery::Battery() : parameters(""), externalPower(""), chargingTime("") {}

Battery::Battery(const std::string& p, const std::string& ep,
                 const std::string& ct)
        : parameters(p), externalPower(ep), chargingTime(ct) {}

// Set methods
void Battery::setParameters(const std::string& p) {
    parameters = p;
}

void Battery::setExternalPower(const std::string& ep) {
    externalPower = ep;
}

void Battery::setChargingTime(const std::string& ct) {
    chargingTime = ct;
}

// Get methods
std::string Battery::getParameters() const {
    return parameters;
}

std::string Battery::getExternalPower() const {
    return externalPower;
}

std::string Battery::getChargingTime() const {
    return chargingTime;
}

// Print method
void Battery::print() const {
    std::cout << "电池模块参数: " << parameters << std::endl;
    std::cout << "电池模块对外供电: " << externalPower << std::endl;
    std::cout << "电池模块充电时长: " << chargingTime << std::endl;
}

// Save method
void Battery::save(std::ofstream& ofs) const {
    ofs << "Battery Parameters: " << parameters << std::endl;
    ofs << "Battery External Power: " << externalPower << std::endl;
    ofs << "Battery Charging Time: " << chargingTime << std::endl;
}
