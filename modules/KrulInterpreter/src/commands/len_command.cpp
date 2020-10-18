#include "commands/len_command.hpp"

void LenCommand::execute()
{
    const std::string first = this->memory.stack->takeString();

    int result = first.length();

    this->memory.stack->push(result);
}