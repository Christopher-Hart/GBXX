#include <string>
#include "Instruction.h"
#include <vector>
#include <string>
#include <map>
#include <tuple>

using namespace std;

InstructionBody::InstructionBody()
    : value(""), size(0), cycles(0), flags("") {};

InstructionBody::InstructionBody(string value, int size, int cycles, string flags)
{
    this->value = value;
    this->size = size;
    this->cycles = cycles;
    this->flags = flags;
};

Instruction::Instruction(int opcode, string value, int size, int cycles, string flags)
{
    this->opcode = opcode;
    this->body = InstructionBody(value, size, cycles, flags);
};

Instruction::Instruction(int offset, vector<uint8_t> const &buffer)
{
    this->opcode = (int)buffer[offset];
    this->body = instruction_map.at(opcode);
}

void Instruction::printSelf()
{
    printf("%#02x: %s \n\tsize: %d\n\tcycles: %d\n\tflags: %s\n", this->opcode, this->body.value.c_str(), this->body.size, this->body.cycles, this->body.flags.c_str());
};

int Instruction::getSize()
{
    return body.size;
}
