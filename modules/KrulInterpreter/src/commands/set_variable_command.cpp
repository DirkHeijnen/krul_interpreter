#include "commands/set_variable_command.hpp"
#include <iostream>

void SetVariableCommand::execute()
{
    std::string top = this->memory.getCurrentInstruction();
    std::string variableName = top.erase(0, 1);

    std::string variableValue = this->memory.stack->takeString();

    this->memory.variables->set(variableName, variableValue);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[=]: Setting variable [ " << variableName << " ] to : [ " << variableValue << " ]" << std::endl;
}
