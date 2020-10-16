#ifndef CPP1_EINDOPDRACHT_IDX_COMMAND_HPP
#define CPP1_EINDOPDRACHT_IDX_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class IdxCommand final : public ICommand
{
    public:
        IdxCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_IDX_COMMAND_HPP
