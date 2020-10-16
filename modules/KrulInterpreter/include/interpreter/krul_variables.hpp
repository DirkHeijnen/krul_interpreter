#ifndef CPP1_EINDOPDRACHT_KRUL_VARIABLES_HPP
#define CPP1_EINDOPDRACHT_KRUL_VARIABLES_HPP

#include <map>
#include <string>

class KrulVariables
{
    public:
        std::string get(const std::string& variableName) const;
        void set(const std::string& variableName, const std::string& variableValue);

    private:
        std::map<std::string, std::string> variables;
};

#endif //CPP1_EINDOPDRACHT_KRUL_VARIABLES_HPP
