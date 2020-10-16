#include "commands/rot_command.hpp"
#include <iostream>

void RotCommand::execute()
{
    std::string first = this->memory.stack->takeString();

    std::string result = this->ROT13(first);

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << "[ROT]: Taking from stack [ " << first << " ] and inserting on stack: [ " << result << " ]" << std::endl;
}

std::string RotCommand::ROT13(std::string source)
{
    for (int i = 0; i < source.size(); i++)
    {
        if (source[i] < 91 && source[i] > 64) // Uppercase
        {
            if (source[i] < 78)
            {
                source[i] = source[i] + 13;
            }
            else
            {
                source[i] = source[i] - 13;
            }
        }
        if (source[i] < 123 && source[i] > 96) // Lowercase
        {
            if (source[i] < 110)
            {
                source[i] = source[i] + 13;
            }
            else
            {
                source[i] = source[i] - 13;
            }
        }
    }

    return source;
}
