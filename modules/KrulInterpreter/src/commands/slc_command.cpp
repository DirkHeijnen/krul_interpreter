#include "commands/slc_command.hpp"

void SlcCommand::execute()
{
    int to = this->memory.stack->takeInt();
    int from = this->memory.stack->takeInt();
    const std::string fullString = this->memory.stack->takeString();

    const std::string result = fullString.substr(from, to - from);

    this->memory.stack->push(result);
}
