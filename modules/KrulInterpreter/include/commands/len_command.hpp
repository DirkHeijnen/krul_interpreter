#ifndef CPP1_EINDOPDRACHT_LEN_COMMAND_HPP
#define CPP1_EINDOPDRACHT_LEN_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class LenCommand final : public ICommand
{
    public:
        LenCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_LEN_COMMAND_HPP
