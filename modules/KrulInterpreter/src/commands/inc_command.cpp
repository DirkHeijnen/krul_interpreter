#include "commands/inc_command.hpp"

void IncCommand::execute()
{
    int first = this->memory.stack->takeInt();

    int result = first + 1;

    this->memory.stack->push(result);
}