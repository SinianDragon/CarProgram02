// Wheel.cpp
#include "Wheel.h"
#include <iostream>

// Constructors
Wheel::Wheel() : model(""), size("") {}

Wheel::Wheel(const std::string& m, const std::string& s) : model(m), size(s) {}

// Set methods
void Wheel::setModel(const std::string& m) {
    model = m;
}

void Wheel::setSize(const std::string& s) {
    size = s;
}

// Get methods
std::string Wheel::getModel() const {
    return model;
}

std::string Wheel::getSize() const {
    return size;
}

// Print method
void Wheel::print(int wheelNumber) const {
    std::cout << "轮胎" << wheelNumber << "型号: " << model << std::endl;
    std::cout << "轮胎" << wheelNumber << "尺寸: " << size << std::endl;
}

// Save method
void Wheel::save(std::ofstream& ofs, int wheelNumber) const {
    ofs << "Wheel" << wheelNumber << " Model: " << model << std::endl;
    ofs << "Wheel" << wheelNumber << " Size: " << size << std::endl;
}
