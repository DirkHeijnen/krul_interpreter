#ifndef CPP1_EINDOPDRACHT_FUN_COMMAND_HPP
#define CPP1_EINDOPDRACHT_FUN_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class FunCommand final : public ICommand
{
    public:
        FunCommand(KrulMemory& memory) : ICommand(memory) { };
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_FUN_COMMAND_HPP
