#include "commands/abs_command.hpp"

void AbsCommand::execute()
{
    int first = this->memory.stack->takeInt();

    int result = std::abs(first);

    this->memory.stack->push(result);
}
