#include "Student.h"
#include <iostream>
#include <vector>
#include <random>

Student::Student() : studentID(""), name("") {}

Student::Student(const std::string& id, const std::string& name) : studentID(id), name(name) {}


void Student::setStudentID(const std::string& id) {
    studentID = id;
}

void Student::setName(const std::string& n) {
    name = n;
}

// Get methods
std::string Student::getStudentID() const {
    return studentID;
}

std::string Student::getName() const {
    return name;
}

std::string generateRandomChineseName() {
    std::vector<std::string> surnames = {
            "王", "李", "张", "刘", "陈", "杨", "赵", "黄", "周", "吴",
            "徐", "孙", "胡", "朱", "高", "林", "何", "郭", "马", "罗"
    };

    std::vector<std::string> givenNamesSingle = {
            "伟", "芳", "娜", "敏", "静", "丽", "强", "磊", "洋", "勇",
            "艳", "杰", "娟", "涛", "明", "超", "秀英", "霞", "平", "刚"
    };

    std::vector<std::string> givenNamesDouble = {
            "佳", "玲", "静", "丽", "敏", "艳", "强", "磊", "洋", "勇",
            "刚", "平", "辉", "娜", "俊", "华", "丽", "军", "翔", "杰"
    };

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> nameLengthDist(0, 1);
    int nameLength = nameLengthDist(gen);

    std::uniform_int_distribution<> surnameDist(0, surnames.size() - 1);
    std::string surname = surnames[surnameDist(gen)];

    std::string givenName;
    if(nameLength == 0) {
        std::uniform_int_distribution<> givenDist(0, givenNamesSingle.size() -1);
        givenName = givenNamesSingle[givenDist(gen)];
    }
    else {
        std::uniform_int_distribution<> givenDist(0, givenNamesDouble.size() -1);
        givenName = givenNamesDouble[givenDist(gen)] + givenNamesDouble[givenDist(gen)];
    }

    return surname + givenName;
}

// Print method
void Student::print() const {
    std::cout << "学生编号: " << studentID << std::endl;
    std::cout << "学生姓名: " << name << std::endl;
}

// Save method
void Student::save(std::ofstream& ofs) const {
    ofs << "Assigned Student ID: " << studentID << std::endl;
    ofs << "Assigned Student Name: " << name << std::endl;
}
