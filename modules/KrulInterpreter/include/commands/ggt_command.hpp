#ifndef CPP1_EINDOPDRACHT_GGT_COMMAND_HPP
#define CPP1_EINDOPDRACHT_GGT_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class GgtCommand final : public ICommand
{
    public:
        GgtCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_GGT_COMMAND_HPP
