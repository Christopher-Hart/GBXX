#include "Processor.h"

Processor::Processor(vector<uint8_t> const &rom)
    : registers{0},
      programCounter(0),
      stackPointer(0),
      rom(rom) {};

uint8_t Processor::setRegister(GENERAL_REGISTER register_id, uint8_t value)
{
    registers[register_id] = value;
    return registers[register_id];
}

uint8_t Processor::setRegister(GENERAL_REGISTER register_id, int value)
{
    registers[register_id] = (uint8_t)value;
    return registers[register_id];
}

uint8_t Processor::getRegister(GENERAL_REGISTER register_id)
{
    return registers[register_id];
}
