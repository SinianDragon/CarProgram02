// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <fstream>

class Student {
private:
    std::string studentID;
    std::string name;

public:
    // Constructors
    Student();
    Student(const std::string& id, const std::string& name);

    // Set methods
    void setStudentID(const std::string& id);
    void setName(const std::string& name);

    // Get methods
    std::string getStudentID() const;
    std::string getName() const;

    // Print method
    void print() const;

    // Save method
    void save(std::ofstream& ofs) const;
};

#endif // STUDENT_H
