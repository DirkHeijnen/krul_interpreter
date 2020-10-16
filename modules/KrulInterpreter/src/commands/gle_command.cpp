#include "commands/gle_command.hpp"
#include <iostream>

void GleCommand::execute()
{
    int index = this->memory.stack->takeInt();
    int value2 = this->memory.stack->takeInt();
    int value1 = this->memory.stack->takeInt();

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[GLE]: If [ " << value1 << " ] <= [ " << value2 << " ] go to: [ " << index << " ] else go to: [ " << this->memory.getInstructionIndex() << " ]" << std::endl;

    if (value1 <= value2)
    {
        this->memory.setInstructionIndex(index);
    }
}
