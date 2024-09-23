// Camera.h
#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <fstream>

class Camera {
private:
    std::string model; // RealSense D435i
    std::string cameraModel; // D430
    std::string RGB_resolution; // 1920*1080
    std::string RGB_frameRate; // 30
    std::string FOV; //87*58
    std::string depth_frameRate; //90

public:
    // Constructors
    Camera();
    Camera(const std::string& model, const std::string& cameraModel,
           const std::string& rgb_res, const std::string& rgb_fr,
           const std::string& fov, const std::string& depth_fr);

    // Set methods
    void setModel(const std::string& m);
    void setCameraModel(const std::string& cm);
    void setRGB_resolution(const std::string& res);
    void setRGB_frameRate(const std::string& fr);
    void setFOV(const std::string& fov_val);
    void setDepth_frameRate(const std::string& depth_fr);

    // Get methods
    std::string getModel() const;
    std::string getCameraModel() const;
    std::string getRGB_resolution() const;
    std::string getRGB_frameRate() const;
    std::string getFOV() const;
    std::string getDepth_frameRate() const;

    // Print method
    void print() const;

    // Save method
    void save(std::ofstream& ofs) const;
};

#endif // CAMERA_H
