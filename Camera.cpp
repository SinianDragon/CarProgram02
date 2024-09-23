// Camera.cpp
#include "Camera.h"
#include <iostream>

// Constructors
Camera::Camera() : model(""), cameraModel(""), RGB_resolution(""),
                   RGB_frameRate(""), FOV(""), depth_frameRate("") {}

Camera::Camera(const std::string& m, const std::string& cm,
               const std::string& res, const std::string& fr,
               const std::string& fov_val, const std::string& depth_fr)
        : model(m), cameraModel(cm), RGB_resolution(res),
          RGB_frameRate(fr), FOV(fov_val), depth_frameRate(depth_fr) {}

// Set methods
void Camera::setModel(const std::string& m) {
    model = m;
}

void Camera::setCameraModel(const std::string& cm) {
    cameraModel = cm;
}

void Camera::setRGB_resolution(const std::string& res) {
    RGB_resolution = res;
}

void Camera::setRGB_frameRate(const std::string& fr) {
    RGB_frameRate = fr;
}

void Camera::setFOV(const std::string& fov_val) {
    FOV = fov_val;
}

void Camera::setDepth_frameRate(const std::string& depth_fr) {
    depth_frameRate = depth_fr;
}

// Get methods
std::string Camera::getModel() const {
    return model;
}

std::string Camera::getCameraModel() const {
    return cameraModel;
}

std::string Camera::getRGB_resolution() const {
    return RGB_resolution;
}

std::string Camera::getRGB_frameRate() const {
    return RGB_frameRate;
}

std::string Camera::getFOV() const {
    return FOV;
}

std::string Camera::getDepth_frameRate() const {
    return depth_frameRate;
}

// Print method
void Camera::print() const {
    std::cout << "双目摄像头型号: " << model << std::endl;
    std::cout << "摄像头型号: " << cameraModel << std::endl;
    std::cout << "RGB帧分辨率: " << RGB_resolution << std::endl;
    std::cout << "RGB帧率: " << RGB_frameRate << std::endl;
    std::cout << "视场角 (FOV): " << FOV << std::endl;
    std::cout << "深度帧率: " << depth_frameRate << std::endl;
}

// Save method
void Camera::save(std::ofstream& ofs) const {
    ofs << "Camera Model: " << model << std::endl;
    ofs << "Camera: " << cameraModel << std::endl;
    ofs << "RGB Resolution: " << RGB_resolution << std::endl;
    ofs << "RGB Frame Rate: " << RGB_frameRate << std::endl;
    ofs << "FOV: " << FOV << std::endl;
    ofs << "Depth Frame Rate: " << depth_frameRate << std::endl;
}
