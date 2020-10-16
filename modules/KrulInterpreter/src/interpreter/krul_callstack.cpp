#include "interpreter/krul_callstack.hpp"
#include "exceptions/krul_exceptions.hpp"

int KrulCallStack::take()
{
    if (this->callStack.empty())
    {
        throw IndexOutOfRangeException("Expected int, but callstack was empty!");
    }

    int top = this->callStack.top();
    this->callStack.pop();
    return top;
}

void KrulCallStack::push(int value)
{
    this->callStack.push(value);
}
