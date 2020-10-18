#include "commands/add_command.hpp"

void AddCommand::execute()
{
    int first = this->memory.stack->takeInt();
    int second = this->memory.stack->takeInt();

    int result = first + second;

    this->memory.stack->push(result);
}
