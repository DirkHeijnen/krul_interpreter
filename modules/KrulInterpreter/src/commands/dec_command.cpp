#include "commands/dec_command.hpp"

void DecCommand::execute()
{
    int first = this->memory.stack->takeInt();

    int result = first - 1;

    this->memory.stack->push(result);
}
