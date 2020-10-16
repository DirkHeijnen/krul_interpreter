#ifndef CPP1_EINDOPDRACHT_INDEX_OUT_OF_RANGE_EXCEPTION_HPP
#define CPP1_EINDOPDRACHT_INDEX_OUT_OF_RANGE_EXCEPTION_HPP

#include <exceptions/krul_exception.hpp>

class IndexOutOfRangeException final : public KrulException
{
    public:
        explicit IndexOutOfRangeException(const std::string & reason) : KrulException("Index out of range", reason) { }
};

#endif //CPP1_EINDOPDRACHT_INDEX_OUT_OF_RANGE_EXCEPTION_HPP
