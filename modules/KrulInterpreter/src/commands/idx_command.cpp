#include "commands/idx_command.hpp"

void IdxCommand::execute()
{
    int index = this->memory.stack->takeInt();
    const std::string string = this->memory.stack->takeString();

    const std::string result { string.at(index) };

    this->memory.stack->push(result);
}
