#ifndef CPP1_EINDOPDRACHT_GEQ_COMMAND_HPP
#define CPP1_EINDOPDRACHT_GEQ_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class GeqCommand final : public ICommand
{
    public:
        GeqCommand(KrulMemory& memory) : ICommand(memory) { };
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_GEQ_COMMAND_HPP
