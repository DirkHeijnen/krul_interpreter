#ifndef CPP1_EINDOPDRACHT_ROT_COMMAND_HPP
#define CPP1_EINDOPDRACHT_ROT_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class RotCommand final : public ICommand
{
    public:
        RotCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;

    private:
        std::string ROT13(std::string source);
};

#endif //CPP1_EINDOPDRACHT_ROT_COMMAND_HPP
