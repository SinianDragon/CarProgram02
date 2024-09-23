// Gyroscope.cpp
#include "Gyroscope.h"
#include <iostream>

// Constructors
Gyroscope::Gyroscope() : model(""), manufacturer("") {}

Gyroscope::Gyroscope(const std::string& m, const std::string& manu)
        : model(m), manufacturer(manu) {}

// Set methods
void Gyroscope::setModel(const std::string& m) {
    model = m;
}

void Gyroscope::setManufacturer(const std::string& manu) {
    manufacturer = manu;
}

// Get methods
std::string Gyroscope::getModel() const {
    return model;
}

std::string Gyroscope::getManufacturer() const {
    return manufacturer;
}

// Print method
void Gyroscope::print() const {
    std::cout << "9轴陀螺仪型号: " << model << std::endl;
    std::cout << "陀螺仪厂家: " << manufacturer << std::endl;
}

// Save method
void Gyroscope::save(std::ofstream& ofs) const {
    ofs << "Gyroscope Model: " << model << std::endl;
    ofs << "Gyroscope Manufacturer: " << manufacturer << std::endl;
}
