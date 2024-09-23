// Car.h
#ifndef CAR_H
#define CAR_H

#include <string>
#include <vector>
#include <fstream>
#include "Chassis.h"
#include "AGX.h"
#include "Camera.h"
#include "Lidar.h"
#include "Gyroscope.h"
#include "Display.h"
#include "Battery.h"
#include "Student.h"

class Car {
private:
    std::string carID; // Carnum + 16 digits + letter
    Chassis chassis;
    AGX agx;
    Camera camera;
    Lidar lidar;
    Gyroscope gyro;
    Display display;
    Battery battery;
    Student assignedStudent;

public:
    // Constructors
    Car();
    Car(const std::string& carID, const Chassis& chassis, const AGX& agx,
        const Camera& camera, const Lidar& lidar, const Gyroscope& gyro,
        const Display& display, const Battery& battery, const Student& student);

    // Set methods
    void setCarID(const std::string& id);
    void setChassis(const Chassis& ch);
    void setAGX(const AGX& a);
    void setCamera(const Camera& cam);
    void setLidar(const Lidar& lid);
    void setGyroscope(const Gyroscope& g);
    void setDisplay(const Display& d);
    void setBattery(const Battery& b);
    void setAssignedStudent(const Student& s);

    // Get methods
    std::string getCarID() const;
    Chassis getChassis() const;
    AGX getAGX() const;
    Camera getCamera() const;
    Lidar getLidar() const;
    Gyroscope getGyroscope() const;
    Display getDisplay() const;
    Battery getBattery() const;
    Student getAssignedStudent() const;

    // Operations
    void setID(const std::string& id);
    void print() const;
    void save(std::ofstream& ofs) const;
};

#endif // CAR_H
