#ifndef CPP1_EINDOPDRACHT_KRUL_LABELS_HPP
#define CPP1_EINDOPDRACHT_KRUL_LABELS_HPP

#include <map>
#include <string>

class KrulLabels
{
    public:
        int get(const std::string& labelName) const;
        void set(const std::string& labelName, int labelValue);

    private:
        std::map<std::string, int> labels;
};

#endif //CPP1_EINDOPDRACHT_KRUL_LABELS_HPP
