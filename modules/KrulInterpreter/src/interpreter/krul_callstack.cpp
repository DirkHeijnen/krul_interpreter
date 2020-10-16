#include "interpreter/krul_callstack.hpp"

int KrulCallStack::take()
{
    int top = this->callStack.top();
    this->callStack.pop();
    return top;
}

void KrulCallStack::push(int value)
{
    this->callStack.push(value);
}
