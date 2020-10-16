#ifndef CPP1_EINDOPDRACHT_ABS_COMMAND_HPP
#define CPP1_EINDOPDRACHT_ABS_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class AbsCommand final : public ICommand
{
    public:
        AbsCommand(KrulMemory& memory) : ICommand(memory) { };
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_ABS_COMMAND_HPP
