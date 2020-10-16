#include "interpreter/krul_variables.hpp"
#include "exceptions/krul_exceptions.hpp"

std::string KrulVariables::get(const std::string& variableName) const
{
    if (variables.find(variableName) == variables.end())
    {
        throw NoSuchFieldException("There was no value found for: " + variableName);
    }

    return variables.at(variableName);
}

void KrulVariables::set(const std::string& variableName, const std::string& variableValue)
{
    this->variables[variableName] = variableValue;
}
