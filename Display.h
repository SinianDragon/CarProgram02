// Display.h
#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <fstream>

class Display {
private:
    std::string size; //11.6
    std::string model; //super

public:
    // Constructors
    Display();
    Display(const std::string& size, const std::string& model);

    // Set methods
    void setSize(const std::string& s);
    void setModel(const std::string& m);

    // Get methods
    std::string getSize() const;
    std::string getModel() const;

    // Print method
    void print() const;

    // Save method
    void save(std::ofstream& ofs) const;
};

#endif // DISPLAY_H
