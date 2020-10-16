#include "commands/dup_command.hpp"
#include <iostream>

void DupCommand::execute()
{
    std::string first = this->memory.stack->readString();

    this->memory.stack->push(first);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[DUP]: Reading from stack { " << first << " } and insert on stack: [ " << first << " ]" << std::endl;
}
