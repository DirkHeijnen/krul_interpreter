#include "commands/rev_command.hpp"

void RevCommand::execute()
{
    const std::string first = this->memory.stack->takeString();

    std::string result = first;
    std::reverse(result.begin(), result.end());

    this->memory.stack->push(result);
}
