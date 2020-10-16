#ifndef CPP1_EINDOPDRACHT_KRUL_CALLSTACK_HPP
#define CPP1_EINDOPDRACHT_KRUL_CALLSTACK_HPP

#include <stack>

class KrulCallStack
{
    public:
        int take();
        void push(int value);

    private:
        std::stack<int> callStack;
};

#endif //CPP1_EINDOPDRACHT_KRUL_CALLSTACK_HPP
