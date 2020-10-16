#include "commands/div_command.hpp"
#include <iostream>
#include "exceptions/krul_exceptions.hpp"

void DivCommand::execute()
{
    int first = this->memory.stack->takeInt();
    int second = this->memory.stack->takeInt();

    if (first == 0 || second == 0)
    {
        throw DivideByZeroException("You can't divide by zero!");
    }

    int result = second / first;

    this->memory.stack->push(result);

    std::cout << "Instruction " << this->memory.getInstructionIndex() << " : ";
    std::cout << " [DIV] Taking from stack [ " << first << " ] and [ " << second << " ], inserting on stack: [ " << result << " ]" << std::endl;
}
