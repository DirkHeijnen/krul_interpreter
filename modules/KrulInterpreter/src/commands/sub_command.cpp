#include "commands/sub_command.hpp"

void SubCommand::execute()
{
    int first = this->memory.stack->takeInt();
    int second = this->memory.stack->takeInt();

    int result = second - first;

    this->memory.stack->push(result);
}