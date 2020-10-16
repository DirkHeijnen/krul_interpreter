#ifndef CPP1_EINDOPDRACHT_RET_COMMAND_HPP
#define CPP1_EINDOPDRACHT_RET_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class RetCommand final : public ICommand
{
    public:
        RetCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_RET_COMMAND_HPP
