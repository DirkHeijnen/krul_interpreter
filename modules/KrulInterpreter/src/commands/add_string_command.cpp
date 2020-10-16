#include "commands/add_string_command.hpp"

#include <iostream>

void AddStringCommand::execute()
{
    std::string instruction = this->memory.getCurrentInstruction();
    std::string value = instruction.erase(0, 1);

    this->memory.stack->push(value);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[\\] Add string [ " << value << " ] to the stack" << std::endl;
}
