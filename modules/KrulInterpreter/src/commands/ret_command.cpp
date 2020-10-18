#include "commands/ret_command.hpp"

void RetCommand::execute()
{
    this->memory.setInstructionIndex(this->memory.callStack->take());
}
