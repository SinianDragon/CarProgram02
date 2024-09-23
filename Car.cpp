// Car.cpp
#include "Car.h"
#include <iostream>

// Constructors
Car::Car() : carID(""), chassis(), agx(), camera(), lidar(), gyro(),
             display(), battery(), assignedStudent() {}

Car::Car(const std::string& id, const Chassis& ch, const AGX& a,
         const Camera& cam, const Lidar& lid, const Gyroscope& g,
         const Display& d, const Battery& b, const Student& s)
        : carID(id), chassis(ch), agx(a), camera(cam), lidar(lid),
          gyro(g), display(d), battery(b), assignedStudent(s) {}

// Set methods
void Car::setCarID(const std::string& id) {
    carID = id;
}

void Car::setChassis(const Chassis& ch) {
    chassis = ch;
}

void Car::setAGX(const AGX& a) {
    agx = a;
}

void Car::setCamera(const Camera& cam) {
    camera = cam;
}

void Car::setLidar(const Lidar& lid) {
    lidar = lid;
}

void Car::setGyroscope(const Gyroscope& g) {
    gyro = g;
}

void Car::setDisplay(const Display& d) {
    display = d;
}

void Car::setBattery(const Battery& b) {
    battery = b;
}

void Car::setAssignedStudent(const Student& s) {
    assignedStudent = s;
}

// Get methods
std::string Car::getCarID() const {
    return carID;
}

Chassis Car::getChassis() const {
    return chassis;
}

AGX Car::getAGX() const {
    return agx;
}

Camera Car::getCamera() const {
    return camera;
}

Lidar Car::getLidar() const {
    return lidar;
}

Gyroscope Car::getGyroscope() const {
    return gyro;
}

Display Car::getDisplay() const {
    return display;
}

Battery Car::getBattery() const {
    return battery;
}

Student Car::getAssignedStudent() const {
    return assignedStudent;
}

// Operations
void Car::setID(const std::string& id) {
    carID = id;
}

// Print method
void Car::print() const {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "智能小车编号: " << carID << std::endl;
    chassis.print();
    agx.print();
    camera.print();
    lidar.print();
    gyro.print();
    display.print();
    battery.print();
    assignedStudent.print();
    std::cout << "----------------------------------------" << std::endl;
}

// Save method
void Car::save(std::ofstream& ofs) const {
    ofs << "CarID: " << carID << std::endl;
    chassis.save(ofs);
    agx.save(ofs);
    camera.save(ofs);
    lidar.save(ofs);
    gyro.save(ofs);
    display.save(ofs);
    battery.save(ofs);
    assignedStudent.save(ofs);
    ofs << "---" << std::endl;
}
