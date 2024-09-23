// Display.cpp
#include "Display.h"
#include <iostream>

// Constructors
Display::Display() : size(""), model("") {}

Display::Display(const std::string& s, const std::string& m)
        : size(s), model(m) {}

// Set methods
void Display::setSize(const std::string& s_val) {
    size = s_val;
}

void Display::setModel(const std::string& m) {
    model = m;
}

// Get methods
std::string Display::getSize() const {
    return size;
}

std::string Display::getModel() const {
    return model;
}

// Print method
void Display::print() const {
    std::cout << "液晶显示屏尺寸: " << size << std::endl;
    std::cout << "液晶显示屏型号: " << model << std::endl;
}

// Save method
void Display::save(std::ofstream& ofs) const {
    ofs << "Display Size: " << size << std::endl;
    ofs << "Display Model: " << model << std::endl;
}
