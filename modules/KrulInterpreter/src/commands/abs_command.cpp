#include <iostream>
#include "commands/abs_command.hpp"

void AbsCommand::execute()
{
    int first = this->memory.stack->takeInt();

    int result = std::abs(first);

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[ABS]: Take from stack [ " << first << " ] and inserting on stack [ " << result << "]" << std::endl;
}
