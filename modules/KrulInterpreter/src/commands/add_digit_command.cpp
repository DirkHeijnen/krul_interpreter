#include "commands/add_digit_command.hpp"

#include <iostream>

void AddDigitCommand::execute()
{
    this->memory.stack->push(this->memory.getCurrentInstruction());

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[" << this->memory.getCurrentInstruction() << "]: Inserting on stack: [ " << this->memory.getCurrentInstruction() << " ]" << std::endl;
}
