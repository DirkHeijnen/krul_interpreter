#ifndef CPP1_EINDOPDRACHT_SUB_COMMAND_HPP
#define CPP1_EINDOPDRACHT_SUB_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class SubCommand final : public ICommand
{
    public:
        SubCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_SUB_COMMAND_HPP
