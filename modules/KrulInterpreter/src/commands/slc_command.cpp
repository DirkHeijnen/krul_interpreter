#include "commands/slc_command.hpp"
#include <iostream>

void SlcCommand::execute()
{
    int to = this->memory.stack->takeInt();
    int from = this->memory.stack->takeInt();
    std::string fullString = this->memory.stack->takeString();

    std::string result = fullString.substr(from, to - from);

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[SLC]: Taking from stack: to: [ " << to << " ] from [ " << from << " ] and string [ " << fullString << " ] and inserting on stack: [ " << result << " ]" << std::endl;
}
