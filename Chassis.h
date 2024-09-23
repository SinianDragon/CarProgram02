// Chassis.h
#ifndef CHASSIS_H
#define CHASSIS_H

#include <string>
#include <vector>
#include <fstream>
#include "Wheel.h"

class Chassis {
private:
    std::string chassisID; // Chasislnum + 8 digits + letter
    std::string model;     // SCOUT MINI
    std::string wheelbase; // 451mm
    std::string trackWidth; // 490mm
    std::string minGroundClearance; // 115mm
    std::string minTurningRadius; // 0m
    std::string driveType; // 四轮四驱
    std::string maxTravel; // 10KM
    std::vector<Wheel> wheels; // 4 wheels

public:
    // Constructors
    Chassis();
    Chassis(const std::string& id, const std::string& model, const std::string& wheelbase,
            const std::string& trackWidth, const std::string& minGroundClearance,
            const std::string& minTurningRadius, const std::string& driveType,
            const std::string& maxTravel, const std::vector<Wheel>& wheels);

    // Set methods
    void setChassisID(const std::string& id);
    void setModel(const std::string& m);
    void setWheelbase(const std::string& wb);
    void setTrackWidth(const std::string& tw);
    void setMinGroundClearance(const std::string& mgc);
    void setMinTurningRadius(const std::string& mtr);
    void setDriveType(const std::string& dt);
    void setMaxTravel(const std::string& mt);
    void setWheels(const std::vector<Wheel>& w);

    // Get methods
    std::string getChassisID() const;
    std::string getModel() const;
    std::string getWheelbase() const;
    std::string getTrackWidth() const;
    std::string getMinGroundClearance() const;
    std::string getMinTurningRadius() const;
    std::string getDriveType() const;
    std::string getMaxTravel() const;
    std::vector<Wheel> getWheels() const;

    // Print method
    void print() const;

    // Save method
    void save(std::ofstream& ofs) const;
};

#endif // CHASSIS_H
