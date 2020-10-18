#include "commands/add_digit_command.hpp"

void AddDigitCommand::execute()
{
    this->memory.stack->push(this->memory.getCurrentInstruction());
}
