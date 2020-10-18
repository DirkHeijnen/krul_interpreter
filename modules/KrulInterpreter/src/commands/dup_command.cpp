#include "commands/dup_command.hpp"

void DupCommand::execute()
{
    const std::string first = this->memory.stack->readString();

    this->memory.stack->push(first);
}
