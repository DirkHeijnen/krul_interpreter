#include <commands/cat_command.hpp>

void CatCommand::execute()
{
    const std::string first = this->memory.stack->takeString();
    const std::string second = this->memory.stack->takeString();

    const std::string result = second + first;

    this->memory.stack->push(result);
}
