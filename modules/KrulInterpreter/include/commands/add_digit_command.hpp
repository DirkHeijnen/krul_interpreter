#ifndef CPP1_EINDOPDRACHT_ADD_DIGIT_COMMAND_HPP
#define CPP1_EINDOPDRACHT_ADD_DIGIT_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class AddDigitCommand final : public ICommand
{
    public:
        AddDigitCommand(KrulMemory& memory) : ICommand(memory) { };
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_ADD_DIGIT_COMMAND_HPP