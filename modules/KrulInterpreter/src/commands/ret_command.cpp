#include "commands/ret_command.hpp"
#include <iostream>

void RetCommand::execute()
{
    int index = this->memory.callStack->take();

    this->memory.setInstructionIndex(index);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[RET]: Taking from callstack [ " << index << " ] and going to index [ " << index << " ]" << std::endl;
}
