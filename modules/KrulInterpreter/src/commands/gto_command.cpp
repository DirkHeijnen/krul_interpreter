#include "commands/gto_command.hpp"

void GtoCommand::execute()
{
    this->memory.setInstructionIndex(this->memory.stack->takeInt());
}

