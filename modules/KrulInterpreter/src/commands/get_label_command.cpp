#include "commands/get_label_command.hpp"

void GetLabelCommand::execute()
{
    const std::string label = this->memory.getCurrentInstruction().erase(0, 1);

    int labelValue = this->memory.labels->get(label);

    this->memory.stack->push(labelValue);
}
