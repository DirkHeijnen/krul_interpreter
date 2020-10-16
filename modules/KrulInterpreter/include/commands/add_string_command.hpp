#ifndef CPP1_EINDOPDRACHT_ADD_STRING_COMMAND_HPP
#define CPP1_EINDOPDRACHT_ADD_STRING_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class AddStringCommand final : public ICommand
{
    public:
        AddStringCommand(KrulMemory& memory) : ICommand(memory) { };
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_ADD_STRING_COMMAND_HPP
