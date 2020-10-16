#ifndef CPP1_EINDOPDRACHT_CAT_COMMAND_HPP
#define CPP1_EINDOPDRACHT_CAT_COMMAND_HPP

#include "interpreter/krul_memory.hpp"
#include "icommand.hpp"

class CatCommand final : public ICommand
{
    public:
        CatCommand(KrulMemory& memory) : ICommand(memory) { };
        void execute() override;
};

#endif //CPP1_EINDOPDRACHT_CAT_COMMAND_HPP

