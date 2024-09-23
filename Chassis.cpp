// Chassis.cpp
#include "Chassis.h"
#include <iostream>

// Constructors
Chassis::Chassis() : chassisID(""), model(""), wheelbase(""), trackWidth(""),
                     minGroundClearance(""), minTurningRadius(""),
                     driveType(""), maxTravel("") {}

Chassis::Chassis(const std::string& id, const std::string& m, const std::string& wb,
                 const std::string& tw, const std::string& mgc,
                 const std::string& mtr, const std::string& dt,
                 const std::string& mt, const std::vector<Wheel>& w)
        : chassisID(id), model(m), wheelbase(wb), trackWidth(tw),
          minGroundClearance(mgc), minTurningRadius(mtr),
          driveType(dt), maxTravel(mt), wheels(w) {}

// Set methods
void Chassis::setChassisID(const std::string& id) {
    chassisID = id;
}

void Chassis::setModel(const std::string& m) {
    model = m;
}

void Chassis::setWheelbase(const std::string& wb) {
    wheelbase = wb;
}

void Chassis::setTrackWidth(const std::string& tw) {
    trackWidth = tw;
}

void Chassis::setMinGroundClearance(const std::string& mgc) {
    minGroundClearance = mgc;
}

void Chassis::setMinTurningRadius(const std::string& mtr) {
    minTurningRadius = mtr;
}

void Chassis::setDriveType(const std::string& dt) {
    driveType = dt;
}

void Chassis::setMaxTravel(const std::string& mt) {
    maxTravel = mt;
}

void Chassis::setWheels(const std::vector<Wheel>& w) {
    wheels = w;
}

// Get methods
std::string Chassis::getChassisID() const {
    return chassisID;
}

std::string Chassis::getModel() const {
    return model;
}

std::string Chassis::getWheelbase() const {
    return wheelbase;
}

std::string Chassis::getTrackWidth() const {
    return trackWidth;
}

std::string Chassis::getMinGroundClearance() const {
    return minGroundClearance;
}

std::string Chassis::getMinTurningRadius() const {
    return minTurningRadius;
}

std::string Chassis::getDriveType() const {
    return driveType;
}

std::string Chassis::getMaxTravel() const {
    return maxTravel;
}

std::vector<Wheel> Chassis::getWheels() const {
    return wheels;
}

// Print method
void Chassis::print() const {
    std::cout << "底盘编号: " << chassisID << std::endl;
    std::cout << "底盘型号: " << model << std::endl;
    std::cout << "轴距: " << wheelbase << std::endl;
    std::cout << "轮距: " << trackWidth << std::endl;
    std::cout << "最小离地间隙: " << minGroundClearance << std::endl;
    std::cout << "最小转弯半径: " << minTurningRadius << std::endl;
    std::cout << "驱动形式: " << driveType << std::endl;
    std::cout << "最大行程: " << maxTravel << std::endl;
    // Print wheels
    for(size_t i = 0; i < wheels.size(); ++i) {
        wheels[i].print(i+1);
    }
}

// Save method
void Chassis::save(std::ofstream& ofs) const {
    ofs << "ChassisID: " << chassisID << std::endl;
    ofs << "Chassis Model: " << model << std::endl;
    ofs << "Wheelbase: " << wheelbase << std::endl;
    ofs << "Track Width: " << trackWidth << std::endl;
    ofs << "Min Ground Clearance: " << minGroundClearance << std::endl;
    ofs << "Min Turning Radius: " << minTurningRadius << std::endl;
    ofs << "Drive Type: " << driveType << std::endl;
    ofs << "Max Travel: " << maxTravel << std::endl;
    // Save wheels
    for(size_t i = 0; i < wheels.size(); ++i) {
        wheels[i].save(ofs, i+1);
    }
}
