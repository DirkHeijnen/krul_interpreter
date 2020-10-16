#ifndef CPP1_EINDOPDRACHT_KRUL_MEMORY_HPP
#define CPP1_EINDOPDRACHT_KRUL_MEMORY_HPP

#include <vector>
#include <memory>

#include "krul_stack.hpp"
#include "krul_callstack.hpp"
#include "krul_variables.hpp"
#include "krul_labels.hpp"

class KrulMemory
{
    public:
        std::unique_ptr<KrulStack> stack = std::make_unique<KrulStack>();
        std::unique_ptr<KrulCallStack> callStack = std::make_unique<KrulCallStack>();
        std::unique_ptr<KrulVariables> variables = std::make_unique<KrulVariables>();
        std::unique_ptr<KrulLabels> labels = std::make_unique<KrulLabels>();

        std::string getCurrentInstruction() const;

        int getInstructionIndex() const;

        void setInstructionIndex(int index);

        void addInstruction(const std::string& instruction);

    private:
        friend class KrulProgram;

        std::vector<std::string> instructions;
        int instructionIndex;
};

#endif //CPP1_EINDOPDRACHT_KRUL_MEMORY_HPP
