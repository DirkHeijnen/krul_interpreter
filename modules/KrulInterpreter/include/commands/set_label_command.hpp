#ifndef CPP1_EINDOPDRACHT_SET_LABEL_COMMAND_HPP
#define CPP1_EINDOPDRACHT_SET_LABEL_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class SetLabelCommand final : public ICommand
{
    public:
        SetLabelCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_SET_LABEL_COMMAND_HPP
