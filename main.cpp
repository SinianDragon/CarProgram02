// main.cpp
#include <bits/stdc++.h>
#include "Car.h"
#include "Chassis.h"
#include "AGX.h"
#include "Camera.h"
#include "Lidar.h"
#include "Gyroscope.h"
#include "Display.h"
#include "Battery.h"
#include "Student.h"
#include "Wheel.h"
using namespace  std;
// 生成小车ID
string generateCarID(int index) {
    stringstream ss;
    ss << "Carnum" << setw(16) << setfill('0') << index;
    char letter = 'A' + (index % 26);
    ss << letter;
    return ss.str();
}

// 生成底盘ID
string generateChassisID(int index) {
    stringstream ss;
    ss << "Chasislnum" << setw(8) << setfill('0') << index;
    char letter = 'A' + (index % 26);
    ss << letter;
    return ss.str();
}
vector<Car> generateCars(int numCars) {
    vector<Car> cars;
    // Wheels: 4个, 公路轮 和 麦克纳姆轮
    vector<Wheel> wheels;
    for(int i=0; i<4; ++i) {
        Wheel w;
        if(i % 2 == 0)
            w.setModel("公路轮");
        else
            w.setModel("麦克纳姆轮");
        w.setSize("175mm");
        wheels.push_back(w);
    }
    // AGX
    AGX agx;
    agx.setModel("AGX Xavier");
    agx.setAI("32 TOPS");
    agx.setCUDA_core("512");
    agx.setTensor_CORE("64");
    agx.setVRAM("32G");
    agx.setStorage("32G");
    // Camera
    Camera camera;
    camera.setModel("RealSense D435i");
    camera.setCameraModel("D430");
    camera.setRGB_resolution("1920*1080");
    camera.setRGB_frameRate("30");
    camera.setFOV("87*58");
    camera.setDepth_frameRate("90");
    // Lidar
    Lidar lidar;
    lidar.setModel("RS-Helios-16p");
    lidar.setChannels(16);
    lidar.setRange("100m");
    lidar.setPower("8W");
    // Gyroscope
    Gyroscope gyro;
    gyro.setModel("CH110");
    gyro.setManufacturer("NXP");
    // Display
    Display display;
    display.setSize("11.6");
    display.setModel("super");
    // Battery
    Battery battery;
    battery.setParameters("24V/15Ah");
    battery.setExternalPower("24V");
    battery.setChargingTime("2H");
    for(int i=1; i<=numCars; ++i) {
        string carID = generateCarID(i);
        string chassisID = generateChassisID(i);
        // 创造底盘
        Chassis chassis;
        chassis.setChassisID(chassisID);
        chassis.setModel("SCOUT MINI");
        chassis.setWheelbase("451mm");
        chassis.setTrackWidth("490mm");
        chassis.setMinGroundClearance("115mm");
        chassis.setMinTurningRadius("0m");
        chassis.setDriveType("四轮四驱");
        chassis.setMaxTravel("10KM");
        chassis.setWheels(wheels);
        // 创造学生
        Student student;
        stringstream ss;
        ss << "E" << setw(4) << setfill('0') << i;
        student.setStudentID(ss.str());

        // 随机姓列表
        vector<string> surnames = {
                "王", "李", "张", "刘", "陈", "杨", "赵", "黄", "周", "吴",
                "徐", "孙", "胡", "朱", "高", "林", "何", "郭", "马", "罗"
        };

        // 随机单名列表
        vector<string> givenNamesSingle = {
                "伟", "芳", "娜", "敏", "静", "丽", "强", "磊", "洋", "勇",
                "艳", "杰", "娟", "涛", "明", "超", "秀英", "霞", "平", "刚"
        };

        // 随机双名列表
        vector<string> givenNamesDouble = {
                "佳", "玲", "静", "丽", "敏", "艳", "强", "磊", "洋", "勇",
                "刚", "平", "辉", "娜", "俊", "华", "丽", "军", "翔", "杰"
        };

        // 生成随机数字
        static random_device rd;
        static mt19937 gen(rd());

        uniform_int_distribution<> nameLengthDist(0, 1);
        int nameLength = nameLengthDist(gen); // 0: single, 1: double

        uniform_int_distribution<> surnameDist(0, surnames.size() - 1);
        string surname = surnames[surnameDist(gen)];
        string givenName;
        if(nameLength == 0) {
            uniform_int_distribution<> givenDist(0, givenNamesSingle.size() -1);
            givenName = givenNamesSingle[givenDist(gen)];
        }
        else {
            uniform_int_distribution<> givenDist(0, givenNamesDouble.size() -1);
            givenName = givenNamesDouble[givenDist(gen)] + givenNamesDouble[givenDist(gen)];
        }

        student.setName(surname + givenName);

        // 生成小车咯
        Car car;
        car.setCarID(carID);
        car.setChassis(chassis);
        car.setAGX(agx);
        car.setCamera(camera);
        car.setLidar(lidar);
        car.setGyroscope(gyro);
        car.setDisplay(display);
        car.setBattery(battery);
        car.setAssignedStudent(student);

        cars.push_back(car);
    }

    return cars;
}

// 将小车信息保存
void saveCarsToFile(const vector<Car>& cars, const string& filename) {
    ofstream ofs(filename, ios::out | ios::trunc);
    if(!ofs.is_open()) {
        cout << "无法打开文件进行写入。" << endl;
        return;
    }

    for(const auto& car : cars) {
        car.save(ofs);
    }

    ofs.close();
    cout << "数据已成功保存到 " << filename << " 文件中。" << endl;
}

// 读取小车信息
vector<Car> loadCarsFromFile(const string& filename) {
    vector<Car> cars;
    ifstream ifs(filename);
    if(!ifs.is_open()) {
        cout << "无法打开文件进行读取。" << endl;
        return cars;
    }

    string line;
    Car car;
    Chassis chassis;
    AGX agx;
    Camera camera;
    Lidar lidar;
    Gyroscope gyro;
    Display display;
    Battery battery;
    Student student;
    vector<Wheel> wheels(4); // Initialize 4 wheels

    while(getline(ifs, line)) {
        if(line == "---") {
            car.setChassis(chassis);
            car.setAGX(agx);
            car.setCamera(camera);
            car.setLidar(lidar);
            car.setGyroscope(gyro);
            car.setDisplay(display);
            car.setBattery(battery);
            car.setAssignedStudent(student);
            cars.push_back(car);
            car = Car();
            chassis = Chassis();
            agx = AGX();
            camera = Camera();
            lidar = Lidar();
            gyro = Gyroscope();
            display = Display();
            battery = Battery();
            student = Student();
            wheels = vector<Wheel>(4);
            continue;
        }
        size_t pos = line.find(": ");
        if(pos == string::npos) continue;
        string key = line.substr(0, pos);
        string value = line.substr(pos + 2);

        if(key == "CarID") {
            car.setCarID(value);
        }
        else if(key == "ChassisID") {
            chassis.setChassisID(value);
        }
        else if(key == "Chassis Model") {
            chassis.setModel(value);
        }
        else if(key == "Wheelbase") {
            chassis.setWheelbase(value);
        }
        else if(key == "Track Width") {
            chassis.setTrackWidth(value);
        }
        else if(key == "Min Ground Clearance") {
            chassis.setMinGroundClearance(value);
        }
        else if(key == "Min Turning Radius") {
            chassis.setMinTurningRadius(value);
        }
        else if(key == "Drive Type") {
            chassis.setDriveType(value);
        }
        else if(key == "Max Travel") {
            chassis.setMaxTravel(value);
        }
        else if(key.find("Wheel") != string::npos && key.find(" Model") != string::npos) {
            int wheelNum = stoi(key.substr(5,1));
            wheels[wheelNum-1].setModel(value);
        }
        else if(key.find("Wheel") != string::npos && key.find(" Size") != string::npos) {
            int wheelNum = stoi(key.substr(5,1));
            wheels[wheelNum-1].setSize(value);
        }
        else if(key == "AGX Model") {
            agx.setModel(value);
        }
        else if(key == "AI") {
            agx.setAI(value);
        }
        else if(key == "CUDA Core") {
            agx.setCUDA_core(value);
        }
        else if(key == "Tensor CORE") {
            agx.setTensor_CORE(value);
        }
        else if(key == "VRAM") {
            agx.setVRAM(value);
        }
        else if(key == "Storage") {
            agx.setStorage(value);
        }
        else if(key == "Camera Model") {
            camera.setModel(value);
        }
        else if(key == "Camera") {
            camera.setCameraModel(value);
        }
        else if(key == "RGB Resolution") {
            camera.setRGB_resolution(value);
        }
        else if(key == "RGB Frame Rate") {
            camera.setRGB_frameRate(value);
        }
        else if(key == "FOV") {
            camera.setFOV(value);
        }
        else if(key == "Depth Frame Rate") {
            camera.setDepth_frameRate(value);
        }
        else if(key == "Lidar Model") {
            lidar.setModel(value);
        }
        else if(key == "Channels") {
            lidar.setChannels(stoi(value));
        }
        else if(key == "Range") {
            lidar.setRange(value);
        }
        else if(key == "Power") {
            lidar.setPower(value);
        }
        else if(key == "Gyroscope Model") {
            gyro.setModel(value);
        }
        else if(key == "Gyroscope Manufacturer") {
            gyro.setManufacturer(value);
        }
        else if(key == "Display Size") {
            display.setSize(value);
        }
        else if(key == "Display Model") {
            display.setModel(value);
        }
        else if(key == "Battery Parameters") {
            battery.setParameters(value);
        }
        else if(key == "Battery External Power") {
            battery.setExternalPower(value);
        }
        else if(key == "Battery Charging Time") {
            battery.setChargingTime(value);
        }
        else if(key == "Assigned Student ID") {
            student.setStudentID(value);
        }
        else if(key == "Assigned Student Name") {
            student.setName(value);
        }
    }
    if(!car.getCarID().empty()) {
        car.setChassis(chassis);
        car.setAGX(agx);
        car.setCamera(camera);
        car.setLidar(lidar);
        car.setGyroscope(gyro);
        car.setDisplay(display);
        car.setBattery(battery);
        car.setAssignedStudent(student);
        cars.push_back(car);
    }
    ifs.close();
    return cars;
}

// 展示小车信息在输出导航面板上
void displayCars(const vector<Car>& cars) {
    if(cars.empty()) {
        cout << "没有小车信息可显示。" << endl;
        return;
    }

    int current = 0;
    while(true) {
        system("cls");
        cars[current].print();
        cout << "\n按n显示下一辆小车, 按p显示上一辆小车, 按q退出, 输出回车确认: ";
        char choice;
        cin >> choice;
        if(choice == 'n' || choice == 'N') {
            if(current < static_cast<int>(cars.size()) - 1) {
                current++;
            }
            else {
                cout << "已经是最后一辆小车啦。" << endl;
                cout << "按回车键继续...";
                cin.ignore(); // Ignore the newline character left in the buffer
                cin.get();
            }
        }
        else if(choice == 'p' || choice == 'P') {
            if(current > 0) {
                current--;
            }
            else {
                cout << "已经是第一辆小车啦。" << endl;
                cout << "按回车键继续...";
                cin.ignore(); // Ignore the newline character left in the buffer
                cin.get();
            }
        }
        else if(choice == 'q' || choice == 'Q') {
            break;
        }
    }
}

int main(){
    // Step 1: 生成小车和对应学生信息
    int numCars = 10;
    vector<Car> cars = generateCars(numCars);

    // Step 2: 保存文件
    string filename = "CarProgram2_data.txt";
    saveCarsToFile(cars, filename);

    // Step 3: 读取文件
    vector<Car> loadedCars = loadCarsFromFile(filename);

    // Step 4: 展示信息
    displayCars(loadedCars);

    return 0;
}
