#include "commands/get_label_command.hpp"
#include <iostream>

void GetLabelCommand::execute()
{
    std::string top = this->memory.getCurrentInstruction();
    std::string labelName = top.erase(0, 1);

    int labelValue = this->memory.labels->get(labelName);

    this->memory.stack->push(labelValue);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[>]: Setting label value of [ " << labelName << " ] on stack: [ " << labelValue << " ]" << std::endl;
}
