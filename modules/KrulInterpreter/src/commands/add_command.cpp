#include "commands/add_command.hpp"
#include <iostream>

void AddCommand::execute()
{
    int first = this->memory.stack->takeInt();
    int second = this->memory.stack->takeInt();

    int result = first + second;

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[ADD]: Take from stack [ " << first << " ] and [ " << second << " ] and inserting on stack [ " << result << " ]" << std::endl;
}


