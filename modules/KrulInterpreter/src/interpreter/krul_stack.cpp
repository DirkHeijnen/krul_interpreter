#include "interpreter/krul_stack.hpp"
#include "exceptions/krul_exceptions.hpp"

std::string KrulStack::takeString()
{
    if (stack.empty())
    {
        throw IndexOutOfRangeException("Expected string, but stack was empty!");
    }

    std::string top = stack.top();
    stack.pop();
    return top;
}

int KrulStack::takeInt()
{
    if (stack.empty())
    {
        throw IndexOutOfRangeException("Expected int, but stack was empty!");
    }

    try
    {
        int top = std::stoi(stack.top());
        stack.pop();
        return top;
    }
    catch (std::exception& e)
    {
        throw IllegalArgumentException("Expected int but got: " + stack.top());
    }
}

std::string KrulStack::readString() const
{
    if (stack.empty())
    {
        throw IndexOutOfRangeException("Expected string, but stack was empty!");
    }

    return stack.top();
}

int KrulStack::readInt() const
{
    if (stack.empty())
    {
        throw IndexOutOfRangeException("Expected int, but stack was empty!");
    }

    try
    {
        return std::stoi(stack.top());
    }
    catch (std::exception e)
    {
        throw IllegalArgumentException("Expected int but got: " + stack.top());
    }
}

void KrulStack::push(const std::string& value)
{
    stack.push(value);
}

void KrulStack::push(int value)
{
    stack.push(std::to_string(value));
}
