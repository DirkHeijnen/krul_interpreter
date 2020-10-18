#include "commands/ggt_command.hpp"

void GgtCommand::execute()
{
    int index = this->memory.stack->takeInt();
    int value2 = this->memory.stack->takeInt();
    int value1 = this->memory.stack->takeInt();

    if (value1 > value2)
    {
        this->memory.setInstructionIndex(index);
    }
}
