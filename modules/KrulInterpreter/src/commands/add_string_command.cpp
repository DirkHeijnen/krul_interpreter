#include "commands/add_string_command.hpp"

void AddStringCommand::execute()
{
    const std::string value = this->memory.getCurrentInstruction().erase(0, 1);
    this->memory.stack->push(value);
}
