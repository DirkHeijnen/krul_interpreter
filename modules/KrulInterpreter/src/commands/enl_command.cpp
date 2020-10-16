#include "commands/enl_command.hpp"
#include <iostream>

void EnlCommand::execute()
{
    std::string first = this->memory.stack->takeString();

    first += "\n";

    this->memory.stack->push(first);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[ENL]: Taking from stack [ " << first << " ] and insert on stack: [ " << first << " ]" << std::endl;
}
