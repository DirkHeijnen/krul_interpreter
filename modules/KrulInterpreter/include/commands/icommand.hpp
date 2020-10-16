#ifndef CPP1_EINDOPDRACHT_ICOMMAND_HPP
#define CPP1_EINDOPDRACHT_ICOMMAND_HPP

#include <interpreter/krul_memory.hpp>

class ICommand
{
    public:
        ICommand(KrulMemory& memory) : memory(memory) { }
        virtual void execute() = 0;

    protected:
        KrulMemory& memory;
};

#endif //CPP1_EINDOPDRACHT_ICOMMAND_HPP
