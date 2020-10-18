#include "commands/set_variable_command.hpp"

void SetVariableCommand::execute()
{
    const std::string variable = this->memory.getCurrentInstruction().erase(0, 1);
    const std::string variableValue = this->memory.stack->takeString();

    this->memory.variables->set(variable, variableValue);
}
