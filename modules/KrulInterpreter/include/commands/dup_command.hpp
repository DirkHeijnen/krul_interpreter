#ifndef CPP1_EINDOPDRACHT_DUP_COMMAND_HPP
#define CPP1_EINDOPDRACHT_DUP_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class DupCommand final : public ICommand
{
    public:
        DupCommand(KrulMemory& memory) : ICommand(memory) { };
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_DUP_COMMAND_HPP
