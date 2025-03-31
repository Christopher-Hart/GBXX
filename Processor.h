#include <cstdint>

using namespace std;
#pragma once

enum GENERAL_REGISTER
{
    A,
    B,
    C,
    D,
    E,
    F,
    H,
    L,
};

class Processor
{
private:
    uint8_t registers[8];
    uint16_t programCounter;
    uint16_t stackPointer;

public:
    Processor();
    uint8_t setRegisters(GENERAL_REGISTER register_index, uint8_t value);
    uint8_t setRegisters(GENERAL_REGISTER register_index, int value);
    uint8_t getRegister(GENERAL_REGISTER register_index);
    uint16_t getProgramCounter();
    uint16_t getStackPointerfd();
};