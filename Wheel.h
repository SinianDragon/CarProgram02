// Wheel.h
#ifndef WHEEL_H
#define WHEEL_H

#include <string>
#include <fstream>

class Wheel {
private:
    std::string model; // 公路轮 or 麦克纳姆轮
    std::string size;  // 175mm

public:
    // Constructors
    Wheel();
    Wheel(const std::string& model, const std::string& size);

    // Set methods
    void setModel(const std::string& model);
    void setSize(const std::string& size);

    // Get methods
    std::string getModel() const;
    std::string getSize() const;

    // Print method
    void print(int wheelNumber) const;

    // Save method
    void save(std::ofstream& ofs, int wheelNumber) const;
};

#endif // WHEEL_H
