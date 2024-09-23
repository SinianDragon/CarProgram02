// AGX.h
#ifndef AGX_H
#define AGX_H

#include <string>
#include <fstream>

class AGX {
private:
    std::string model; // AGX Xavier
    std::string AI; // 32 TOPS
    std::string CUDA_core; // 512
    std::string Tensor_CORE; // 64
    std::string VRAM; // 32G
    std::string storage; //32G

public:
    // Constructors
    AGX();
    AGX(const std::string& model, const std::string& AI, const std::string& CUDA,
        const std::string& Tensor, const std::string& VRAM, const std::string& storage);

    // Set methods
    void setModel(const std::string& m);
    void setAI(const std::string& ai);
    void setCUDA_core(const std::string& cuda);
    void setTensor_CORE(const std::string& tensor);
    void setVRAM(const std::string& vram);
    void setStorage(const std::string& s);

    // Get methods
    std::string getModel() const;
    std::string getAI() const;
    std::string getCUDA_core() const;
    std::string getTensor_CORE() const;
    std::string getVRAM() const;
    std::string getStorage() const;

    // Print method
    void print() const;

    // Save method
    void save(std::ofstream& ofs) const;
};

#endif // AGX_H
