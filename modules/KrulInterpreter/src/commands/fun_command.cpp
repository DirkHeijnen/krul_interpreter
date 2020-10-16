#include "commands/fun_command.hpp"
#include "commands/gto_command.hpp"
#include <iostream>

void FunCommand::execute()
{
    this->memory.callStack->push(this->memory.getInstructionIndex());

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[FUN]: Pushing to callstack: [ " << this->memory.getInstructionIndex() << " ]" << std::endl;

    GtoCommand(this->memory).execute();
}
