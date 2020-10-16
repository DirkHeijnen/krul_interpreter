#ifndef CPP1_EINDOPDRACHT_GLE_COMMAND_HPP
#define CPP1_EINDOPDRACHT_GLE_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class GleCommand final : public ICommand
{
    public:
        GleCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_GLE_COMMAND_HPP
