#include "commands/inc_command.hpp"
#include <iostream>

void IncCommand::execute()
{
    int first = this->memory.stack->takeInt();

    int result = first + 1;

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[INC] Taking from stack [ " << first << " ] and inserting on stack: [ " << result << " ]" << std::endl;
}