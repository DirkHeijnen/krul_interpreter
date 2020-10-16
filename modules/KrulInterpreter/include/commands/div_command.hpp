#ifndef CPP1_EINDOPDRACHT_DIV_COMMAND_HPP
#define CPP1_EINDOPDRACHT_DIV_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class DivCommand final : public ICommand
{
    public:
        DivCommand(KrulMemory& memory) : ICommand(memory) { };
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_DIV_COMMAND_HPP
