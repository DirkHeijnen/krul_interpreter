#include "commands/gne_command.hpp"

void GneCommand::execute()
{
    int index = this->memory.stack->takeInt();
    const std::string value2 = this->memory.stack->takeString();
    const std::string value1 = this->memory.stack->takeString();

    if (value1 != value2)
    {
        this->memory.setInstructionIndex(index);
    }
}
