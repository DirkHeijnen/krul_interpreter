#include "interpreter/krul_labels.hpp"
#include "exceptions/krul_exceptions.hpp"

int KrulLabels::get(const std::string& labelName) const
{
    if (this->labels.find(labelName) == this->labels.end())
    {
        throw NoSuchFieldException("There was no value found for: " + labelName);
    }

    return labels.at(labelName);
}

void KrulLabels::set(const std::string& labelName, int labelValue)
{
    this->labels[labelName] = labelValue;
}
