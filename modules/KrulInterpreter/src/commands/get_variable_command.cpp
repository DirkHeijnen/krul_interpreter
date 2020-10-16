#include "commands/get_variable_command.hpp"
#include <iostream>

void GetVariableCommand::execute()
{
    std::string top = this->memory.getCurrentInstruction();
    std::string variableName = top.erase(0, 1);
    std::string variableValue = this->memory.variables->get(variableName);

    this->memory.stack->push(variableValue);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[$]: Setting variable value of [ " << variableName << " ] on stack: [ " << variableValue << " ]" << std::endl;
}
