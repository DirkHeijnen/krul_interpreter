#include "commands/set_label_command.hpp"

void SetLabelCommand::execute()
{
    const std::string label = this->memory.getCurrentInstruction().erase(0, 1);
    this->memory.labels->set(label, this->memory.getInstructionIndex());
}
