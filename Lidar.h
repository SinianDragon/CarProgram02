// Lidar.h
#ifndef LIDAR_H
#define LIDAR_H

#include <string>
#include <fstream>

class Lidar {
private:
    std::string model; // RS-Helios-16p
    int channels; //16
    std::string range; //100m
    std::string power; //8W

public:
    // Constructors
    Lidar();
    Lidar(const std::string& model, int channels, const std::string& range,
          const std::string& power);

    // Set methods
    void setModel(const std::string& m);
    void setChannels(int ch);
    void setRange(const std::string& r);
    void setPower(const std::string& p);

    // Get methods
    std::string getModel() const;
    int getChannels() const;
    std::string getRange() const;
    std::string getPower() const;

    // Print method
    void print() const;

    // Save method
    void save(std::ofstream& ofs) const;
};

#endif // LIDAR_H
