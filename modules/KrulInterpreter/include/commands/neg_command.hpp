#ifndef CPP1_EINDOPDRACHT_NEG_COMMAND_HPP
#define CPP1_EINDOPDRACHT_NEG_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class NegCommand final : public ICommand
{
    public:
        NegCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_NEG_COMMAND_HPP
