#include "interpreter/krul_program.hpp"
#include "exceptions/krul_exceptions.hpp"
#include <iostream>
#include <sstream>

void KrulProgram::load(const std::string& input)
{
    std::stringstream instructionStream(input);

    for (std::string line; std::getline(instructionStream, line, '\n');)
    {
        this->memory.addInstruction(line);
    }

    preprocess();
}

void KrulProgram::preprocess()
{
    for (this->memory.instructionIndex = 0; this->memory.instructionIndex < this->memory.instructions.size(); this->memory.instructionIndex++)
    {
        const std::string& instruction = this->memory.getCurrentInstruction();

        if (instruction[0] == ':')
        {
            std::cout << "PREPROCESSING: ";
            SetLabelCommand(this->memory).execute();
        }
    }
}

void KrulProgram::execute()
{
    std::cout << std::endl;

    for (this->memory.instructionIndex = 0; this->memory.instructionIndex < this->memory.instructions.size(); this->memory.instructionIndex++)
    {
        // The current instruction
        std::string instruction = this->memory.getCurrentInstruction();

        if (instruction[0] == ':') { continue; }

        // Values & Types
        if (std::isdigit(instruction[0])) { AddDigitCommand(memory).execute(); continue; }
        if (instruction[0] == '\\') { AddStringCommand(memory).execute(); continue; }
        if (instruction[0] == '=') { SetVariableCommand(memory).execute(); continue; }
        if (instruction[0] == '$') { GetVariableCommand(memory).execute(); continue;}
        if (instruction[0] == '>') { GetLabelCommand(memory).execute(); continue; }

        // Integer operations
        if (instruction == "add") { AddCommand(memory).execute(); continue; }
        if (instruction == "sub") { SubCommand(memory).execute(); continue; }
        if (instruction == "mul") { MulCommand(memory).execute(); continue; }
        if (instruction == "div") { DivCommand(memory).execute(); continue; }
        if (instruction == "mod") { ModCommand(memory).execute(); continue; }
        if (instruction == "neg") { NegCommand(memory).execute(); continue; }
        if (instruction == "abs") { AbsCommand(memory).execute(); continue; }
        if (instruction == "inc") { IncCommand(memory).execute(); continue; }
        if (instruction == "dec") { DecCommand(memory).execute(); continue; }

        // String operations
        if (instruction == "dup") { DupCommand(memory).execute(); continue; }
        if (instruction == "rev") { RevCommand(memory).execute(); continue; }
        if (instruction == "slc") { SlcCommand(memory).execute(); continue; }
        if (instruction == "idx") { IdxCommand(memory).execute(); continue; }
        if (instruction == "cat") { CatCommand(memory).execute(); continue; }
        if (instruction == "len") { LenCommand(memory).execute(); continue; }
        if (instruction == "rot") { RotCommand(memory).execute(); continue; }
        if (instruction == "enl") { EnlCommand(memory).execute(); continue; }

        // Tests & Jumps
        if (instruction == "gto") { GtoCommand(memory).execute(); continue; }
        if (instruction == "geq") { GeqCommand(memory).execute(); continue; }
        if (instruction == "gne") { GneCommand(memory).execute(); continue; }
        if (instruction == "glt") { GltCommand(memory).execute(); continue; }
        if (instruction == "gle") { GleCommand(memory).execute(); continue; }
        if (instruction == "ggt") { GgtCommand(memory).execute(); continue; }
        if (instruction == "gge") { GgeCommand(memory).execute(); continue; }

        // Functions
        if (instruction == "fun") { FunCommand(memory).execute(); continue; }
        if (instruction == "ret") { RetCommand(memory).execute(); continue; }

        // End
        if (instruction == "end") { this->isFinished = true; continue; }

        throw NoSuchMethodException("The instruction [" + instruction + "] is not linked to an existing operation");
    }
}
