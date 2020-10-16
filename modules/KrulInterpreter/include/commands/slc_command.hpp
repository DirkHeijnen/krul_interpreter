#ifndef CPP1_EINDOPDRACHT_SLC_COMMAND_HPP
#define CPP1_EINDOPDRACHT_SLC_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class SlcCommand final : public ICommand
{
    public:
        SlcCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_SLC_COMMAND_HPP
