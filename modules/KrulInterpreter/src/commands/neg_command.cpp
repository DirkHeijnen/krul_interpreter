#include "commands/neg_command.hpp"
#include <iostream>

void NegCommand::execute()
{
    int first = this->memory.stack->takeInt();

    int result = -first;

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[NEG]: Taking from stack [ " << first << " ] and inserting on stack: [" << result << " ]" << std::endl;
}
