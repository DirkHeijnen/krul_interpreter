#ifndef CPP1_EINDOPDRACHT_GGE_COMMAND_HPP
#define CPP1_EINDOPDRACHT_GGE_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class GgeCommand final : public ICommand
{
    public:
        GgeCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_GGE_COMMAND_HPP
