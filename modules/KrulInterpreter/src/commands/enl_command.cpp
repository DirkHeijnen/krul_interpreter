#include "commands/enl_command.hpp"

void EnlCommand::execute()
{
    const std::string first = this->memory.stack->takeString();

    const std::string result = first + '\n';

    this->memory.stack->push(result);
}
