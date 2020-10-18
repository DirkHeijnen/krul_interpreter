#include "commands/neg_command.hpp"

void NegCommand::execute()
{
    int first = this->memory.stack->takeInt();

    int result = -first;

    this->memory.stack->push(result);
}
