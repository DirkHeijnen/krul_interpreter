#ifndef CPP1_EINDOPDRACHT_SET_VARIABLE_COMMAND_HPP
#define CPP1_EINDOPDRACHT_SET_VARIABLE_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class SetVariableCommand final : public ICommand
{
    public:
        SetVariableCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_SET_VARIABLE_COMMAND_HPP
