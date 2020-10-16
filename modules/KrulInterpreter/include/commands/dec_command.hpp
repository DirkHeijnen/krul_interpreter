#ifndef CPP1_EINDOPDRACHT_DEC_COMMAND_HPP
#define CPP1_EINDOPDRACHT_DEC_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class DecCommand final : public ICommand
{
    public:
        DecCommand(KrulMemory& memory) : ICommand(memory) { };
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_DEC_COMMAND_HPP
