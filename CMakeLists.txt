cmake_minimum_required(VERSION 3.29)
project(CarProgram02)

set(CMAKE_CXX_STANDARD 26)

add_executable(CarProgram02 main.cpp
        Student.cpp
        Student.h
        Wheel.cpp
        Wheel.h
        Chassis.h
        Chassis.cpp
        AGX.cpp
        AGX.h
        Camera.h
        Camera.cpp
        Lidar.cpp
        Lidar.h
        Gyroscope.cpp
        Gyroscope.h
        Display.h
        Display.cpp
        Battery.h
        Battery.cpp
        Car.cpp
        Car.h)
