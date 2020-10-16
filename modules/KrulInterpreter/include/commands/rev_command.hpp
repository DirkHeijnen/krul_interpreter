#ifndef CPP1_EINDOPDRACHT_REV_COMMAND_HPP
#define CPP1_EINDOPDRACHT_REV_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class RevCommand final : public ICommand
{
    public:
        RevCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_REV_COMMAND_HPP
