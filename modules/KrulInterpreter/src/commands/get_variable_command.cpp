#include "commands/get_variable_command.hpp"

void GetVariableCommand::execute()
{
    const std::string variable = this->memory.getCurrentInstruction().erase(0, 1);
    const std::string variableValue = this->memory.variables->get(variable);

    this->memory.stack->push(variableValue);
}
