#ifndef CPP1_EINDOPDRACHT_KRUL_PROGRAM_HPP
#define CPP1_EINDOPDRACHT_KRUL_PROGRAM_HPP

#include <string>
#include "commands/commands.hpp"
#include "krul_memory.hpp"

class KrulProgram
{
    public:
        void load(std::string input);
        void preprocess();
        void execute();

        bool isFinished = false;
        KrulMemory memory;
};

#endif //CPP1_EINDOPDRACHT_KRUL_PROGRAM_HPP
