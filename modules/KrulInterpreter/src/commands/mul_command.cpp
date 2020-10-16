#include "commands/mul_command.hpp"
#include <iostream>

void MulCommand::execute()
{
    int first = this->memory.stack->takeInt();
    int second = this->memory.stack->takeInt();

    int result = first * second;

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[MOD]: Taking from stack [ " << first << " ] and [ " << second << " ] and inserting on stack: [" << result << " ]" << std::endl;
}
