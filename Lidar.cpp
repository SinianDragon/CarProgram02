// Lidar.cpp
#include "Lidar.h"
#include <iostream>

// Constructors
Lidar::Lidar() : model(""), channels(0), range(""), power("") {}

Lidar::Lidar(const std::string& m, int ch, const std::string& r,
             const std::string& p)
        : model(m), channels(ch), range(r), power(p) {}

// Set methods
void Lidar::setModel(const std::string& m) {
    model = m;
}

void Lidar::setChannels(int ch) {
    channels = ch;
}

void Lidar::setRange(const std::string& r) {
    range = r;
}

void Lidar::setPower(const std::string& p) {
    power = p;
}

// Get methods
std::string Lidar::getModel() const {
    return model;
}

int Lidar::getChannels() const {
    return channels;
}

std::string Lidar::getRange() const {
    return range;
}

std::string Lidar::getPower() const {
    return power;
}

// Print method
void Lidar::print() const {
    std::cout << "多线激光雷达型号: " << model << std::endl;
    std::cout << "通道数: " << channels << std::endl;
    std::cout << "测试范围: " << range << std::endl;
    std::cout << "功耗: " << power << std::endl;
}

// Save method
void Lidar::save(std::ofstream& ofs) const {
    ofs << "Lidar Model: " << model << std::endl;
    ofs << "Channels: " << channels << std::endl;
    ofs << "Range: " << range << std::endl;
    ofs << "Power: " << power << std::endl;
}
