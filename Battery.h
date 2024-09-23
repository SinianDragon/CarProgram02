// Battery.h
#ifndef BATTERY_H
#define BATTERY_H

#include <string>
#include <fstream>

class Battery {
private:
    std::string parameters; //24V/15Ah
    std::string externalPower; //24V
    std::string chargingTime; //2H

public:
    // Constructors
    Battery();
    Battery(const std::string& parameters, const std::string& externalPower,
            const std::string& chargingTime);

    // Set methods
    void setParameters(const std::string& p);
    void setExternalPower(const std::string& ep);
    void setChargingTime(const std::string& ct);

    // Get methods
    std::string getParameters() const;
    std::string getExternalPower() const;
    std::string getChargingTime() const;

    // Print method
    void print() const;

    // Save method
    void save(std::ofstream& ofs) const;
};

#endif // BATTERY_H
