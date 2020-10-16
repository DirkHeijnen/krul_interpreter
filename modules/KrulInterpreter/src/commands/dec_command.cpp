#include "commands/dec_command.hpp"
#include <iostream>

void DecCommand::execute()
{
    int first = this->memory.stack->takeInt();

    int result = first - 1;

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << " [DEC] Taking from stack [ " << first << " ] and inserting on stack: [ " << result << " ]" << std::endl;
}
