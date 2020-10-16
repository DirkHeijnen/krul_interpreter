#include "interpreter/krul_variables.hpp"
#include "exceptions/krul_exceptions.hpp"

std::string KrulVariables::get(std::string variableName) const
{
    if (variables.find(variableName) == variables.end())
    {
        throw NoSuchFieldException("There was no value found for: " + variableName);
    }
    return variables.at(variableName);
}

void KrulVariables::set(std::string variableName, std::string variableValue)
{
    this->variables[variableName] = variableValue;
}
