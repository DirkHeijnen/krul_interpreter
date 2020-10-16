#ifndef CPP1_EINDOPDRACHT_KRUL_STACK_HPP
#define CPP1_EINDOPDRACHT_KRUL_STACK_HPP

#include <stack>
#include <string>

class KrulStack
{
    public:
        std::string takeString();
        std::string readString() const;
        int takeInt();
        int readInt() const;
        void push(std::string value);
        void push(int value);

    private:
        std::stack<std::string> stack;
};

#endif //CPP1_EINDOPDRACHT_KRUL_STACK_HPP
