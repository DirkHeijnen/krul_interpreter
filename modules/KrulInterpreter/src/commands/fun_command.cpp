#include "commands/fun_command.hpp"
#include "commands/gto_command.hpp"

void FunCommand::execute()
{
    this->memory.callStack->push(this->memory.getInstructionIndex());
    GtoCommand(this->memory).execute();
}
