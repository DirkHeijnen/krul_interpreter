#include "commands/set_label_command.hpp"
#include <iostream>

void SetLabelCommand::execute()
{
    std::string top = this->memory.getCurrentInstruction();
    std::string labelName = top.erase(0, 1);

    this->memory.labels->set(labelName, this->memory.getInstructionIndex());

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[:]: Setting label [ " << labelName << " ] to : [ " << this->memory.getInstructionIndex() << " ]" << std::endl;
}
