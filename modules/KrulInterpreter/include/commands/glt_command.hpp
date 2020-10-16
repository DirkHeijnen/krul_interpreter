#ifndef CPP1_EINDOPDRACHT_GLT_COMMAND_HPP
#define CPP1_EINDOPDRACHT_GLT_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class GltCommand final : public ICommand
{
    public:
        GltCommand(KrulMemory& memory) : ICommand(memory) { }
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_GLT_COMMAND_HPP
