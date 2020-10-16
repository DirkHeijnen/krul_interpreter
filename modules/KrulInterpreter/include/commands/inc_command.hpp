#ifndef CPP1_EINDOPDRACHT_INC_COMMAND_HPP
#define CPP1_EINDOPDRACHT_INC_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class IncCommand final : public ICommand
{
    public:
        IncCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_INC_COMMAND_HPP
