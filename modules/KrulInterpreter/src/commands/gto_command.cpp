#include "commands/gto_command.hpp"
#include <iostream>

void GtoCommand::execute()
{
    int first = this->memory.stack->takeInt();
    this->memory.setInstructionIndex(first);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[GTO]: Taking from stack [ " << first << " ] and setting index to: " << first << std::endl;
}

