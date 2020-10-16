#ifndef CPP1_EINDOPDRACHT_GET_VARIABLE_COMMAND_HPP
#define CPP1_EINDOPDRACHT_GET_VARIABLE_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class GetVariableCommand final : public ICommand
{
    public:
        GetVariableCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_GET_VARIABLE_COMMAND_HPP
