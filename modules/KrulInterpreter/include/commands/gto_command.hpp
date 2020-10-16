#ifndef CPP1_EINDOPDRACHT_GTO_COMMAND_HPP
#define CPP1_EINDOPDRACHT_GTO_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class GtoCommand final : public ICommand
{
    public:
        GtoCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_GTO_COMMAND_HPP
