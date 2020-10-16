#include "commands/sub_command.hpp"
#include <iostream>

void SubCommand::execute()
{
    int first = this->memory.stack->takeInt();
    int second = this->memory.stack->takeInt();

    int result = second - first;

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[SUB]: Take from stack [ " << first << " ] and [ " << second << " ] and inserting on stack [ " << result << " ]" << std::endl;
}