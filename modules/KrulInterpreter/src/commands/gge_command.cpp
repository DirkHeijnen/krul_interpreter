#include "commands/gge_command.hpp"

void GgeCommand::execute()
{
    int index = this->memory.stack->takeInt();
    int value2 = this->memory.stack->takeInt();
    int value1 = this->memory.stack->takeInt();

    if (value1 >= value2)
    {
        this->memory.setInstructionIndex(index);
    }
}
