#ifndef CPP1_EINDOPDRACHT_GNE_COMMAND_HPP
#define CPP1_EINDOPDRACHT_GNE_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class GneCommand final : public ICommand
{
    public:
        GneCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_GNE_COMMAND_HPP
