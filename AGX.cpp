// AGX.cpp
#include "AGX.h"
#include <iostream>

// Constructors
AGX::AGX() : model(""), AI(""), CUDA_core(""), Tensor_CORE(""),
             VRAM(""), storage("") {}

AGX::AGX(const std::string& m, const std::string& ai, const std::string& cuda,
         const std::string& tensor, const std::string& vram, const std::string& s)
        : model(m), AI(ai), CUDA_core(cuda), Tensor_CORE(tensor),
          VRAM(vram), storage(s) {}

// Set methods
void AGX::setModel(const std::string& m) {
    model = m;
}

void AGX::setAI(const std::string& ai_val) {
    AI = ai_val;
}

void AGX::setCUDA_core(const std::string& cuda) {
    CUDA_core = cuda;
}

void AGX::setTensor_CORE(const std::string& tensor) {
    Tensor_CORE = tensor;
}

void AGX::setVRAM(const std::string& vram_val) {
    VRAM = vram_val;
}

void AGX::setStorage(const std::string& s) {
    storage = s;
}

// Get methods
std::string AGX::getModel() const {
    return model;
}

std::string AGX::getAI() const {
    return AI;
}

std::string AGX::getCUDA_core() const {
    return CUDA_core;
}

std::string AGX::getTensor_CORE() const {
    return Tensor_CORE;
}

std::string AGX::getVRAM() const {
    return VRAM;
}

std::string AGX::getStorage() const {
    return storage;
}

// Print method
void AGX::print() const {
    std::cout << "AGX型号: " << model << std::endl;
    std::cout << "AI算力: " << AI << std::endl;
    std::cout << "CUDA核心: " << CUDA_core << std::endl;
    std::cout << "Tensor CORE: " << Tensor_CORE << std::endl;
    std::cout << "显存: " << VRAM << std::endl;
    std::cout << "存储: " << storage << std::endl;
}

// Save method
void AGX::save(std::ofstream& ofs) const {
    ofs << "AGX Model: " << model << std::endl;
    ofs << "AI: " << AI << std::endl;
    ofs << "CUDA Core: " << CUDA_core << std::endl;
    ofs << "Tensor CORE: " << Tensor_CORE << std::endl;
    ofs << "VRAM: " << VRAM << std::endl;
    ofs << "Storage: " << storage << std::endl;
}
