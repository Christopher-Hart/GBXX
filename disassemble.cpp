#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Instruction.h"
#include "Processor.h"

std::vector<u_char> readFileToBuffer(std::string filePath)
{
    std::ifstream file;
    std::vector<u_char> fileBuffer;
    file.open(filePath, std::ios::binary | std::ios::ate);
    if (file.is_open())
    {
        file.seekg(0, std::ios::end);
        std::streamsize fileSize = file.tellg();
        file.seekg(0, std::ios::beg);
        fileBuffer.resize(fileSize);
        file.read(reinterpret_cast<char *>(fileBuffer.data()), fileSize);
        file.close();
    }

    return fileBuffer;
}

int main()
{
    // std::vector<u_char> const fileBuffer = readFileToBuffer("gold.rom");
    // int index = 0;
    // std::string opcodes[16][16];

    // for (char byte : fileBuffer)
    // {
    //     std::cout << std::setw(2) << std::setfill('0') << std::hex << (static_cast<int>(byte) & 0xFF);
    //     if ((index + 1) % 16 == 0)
    //     {
    //         std::cout << "\n";
    //     }
    //     index++;
    // }

    // int offset = 0;

    // for (int i = 0; i < 16; i++)
    // {

    //     Instruction bufferTest(offset, fileBuffer);

    //     bufferTest.printSelf();

    //     offset += bufferTest.getSize();
    // }

    Processor cpu = Processor();

    uint8_t aValue = cpu.getRegister(GENERAL_REGISTER::A);

    printf("%#02x\n", aValue);

    cpu.setRegisters(A, 0x101);
    aValue = cpu.getRegister(A);

    printf("%#02x\n", aValue);

    return 0;
}
