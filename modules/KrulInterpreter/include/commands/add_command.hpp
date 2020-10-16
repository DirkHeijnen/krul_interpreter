#ifndef CPP1_EINDOPDRACHT_ADD_COMMAND_HPP
#define CPP1_EINDOPDRACHT_ADD_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class AddCommand final : public ICommand
{
    public:
        AddCommand(KrulMemory& memory) : ICommand(memory) { };
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_ADD_COMMAND_HPP
