#ifndef CPP1_EINDOPDRACHT_MUL_COMMAND_HPP
#define CPP1_EINDOPDRACHT_MUL_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class MulCommand final : public ICommand
{
    public:
        MulCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_MUL_COMMAND_HPP
