// Gyroscope.h
#ifndef GYROSCOPE_H
#define GYROSCOPE_H

#include <string>
#include <fstream>

class Gyroscope {
private:
    std::string model; // CH110
    std::string manufacturer; //NXP

public:
    // Constructors
    Gyroscope();
    Gyroscope(const std::string& model, const std::string& manufacturer);

    // Set methods
    void setModel(const std::string& m);
    void setManufacturer(const std::string& manu);

    // Get methods
    std::string getModel() const;
    std::string getManufacturer() const;

    // Print method
    void print() const;

    // Save method
    void save(std::ofstream& ofs) const;
};

#endif // GYROSCOPE_H
