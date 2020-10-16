#include "commands/idx_command.hpp"
#include <iostream>

void IdxCommand::execute()
{
    int index = this->memory.stack->takeInt();
    std::string string = this->memory.stack->takeString();

    std::string result { string.at(index) };

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[IDX]: Taking from stack [ " << index << " ] and string [ " << string << " ] and inserting on stack: [ " << result << " ]" << std::endl;
}
