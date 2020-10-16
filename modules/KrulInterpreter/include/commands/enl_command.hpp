#ifndef CPP1_EINDOPDRACHT_ENL_COMMAND_HPP
#define CPP1_EINDOPDRACHT_ENL_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class EnlCommand final : public ICommand
{
    public:
        EnlCommand(KrulMemory& memory) : ICommand(memory) { };
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_ENL_COMMAND_HPP
