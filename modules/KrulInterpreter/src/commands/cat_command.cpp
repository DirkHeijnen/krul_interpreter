#include <commands/cat_command.hpp>

#include <iostream>

void CatCommand::execute()
{
    std::string first = this->memory.stack->takeString();
    std::string second = this->memory.stack->takeString();

    std::string result = second + first;

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[CAT] Add together [ " << first << " ] and [ " << second << " ], inserting on stack: [ " << result << " ]" << std::endl;
}
