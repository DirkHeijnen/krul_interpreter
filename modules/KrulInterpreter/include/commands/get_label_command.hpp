#ifndef CPP1_EINDOPDRACHT_GET_LABEL_COMMAND_HPP
#define CPP1_EINDOPDRACHT_GET_LABEL_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class GetLabelCommand final : public ICommand
{
    public:
        GetLabelCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_GET_LABEL_COMMAND_HPP
