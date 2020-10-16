#ifndef CPP1_EINDOPDRACHT_MOD_COMMAND_HPP
#define CPP1_EINDOPDRACHT_MOD_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class ModCommand final : public ICommand
{
    public:
        ModCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_MOD_COMMAND_HPP
