#include "commands/len_command.hpp"
#include <iostream>

void LenCommand::execute()
{
    std::string first = this->memory.stack->takeString();

    int result = first.length();

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[LEN] Taking from stack [ " << first << " ] and inserting on stack: [ " << result << " ]" << std::endl;
}