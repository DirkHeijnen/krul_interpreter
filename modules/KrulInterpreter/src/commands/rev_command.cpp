#include "commands/rev_command.hpp"
#include <iostream>

void RevCommand::execute()
{
    std::string first = this->memory.stack->takeString();

    std::string result = std::string(first);
    std::reverse(result.begin(), result.end());

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[REV]: Taking from stack [ " << first << " ] and inserting on stack: [" << result << " ]" << std::endl;
}
