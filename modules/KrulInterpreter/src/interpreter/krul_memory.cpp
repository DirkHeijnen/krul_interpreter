#include "interpreter/krul_memory.hpp"
#include "exceptions/krul_exceptions.hpp"

std::string KrulMemory::getCurrentInstruction() const
{
    if (this->instructionIndex > this->instructions.size())
    {
        throw IndexOutOfRangeException("The stack pointer does not point to anything!");
    }

    return this->instructions.at(this->instructionIndex);
}

int KrulMemory::getInstructionIndex() const
{
    return this->instructionIndex;
}

void KrulMemory::setInstructionIndex(int index)
{
    this->instructionIndex = index;
}

void KrulMemory::addInstruction(const std::string& instruction)
{
    this->instructions.push_back(instruction);
}
