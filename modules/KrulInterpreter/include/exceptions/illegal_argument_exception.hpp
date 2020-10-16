#ifndef CPP1_EINDOPDRACHT_ILLEGAL_ARGUMENT_EXCEPTION_HPP
#define CPP1_EINDOPDRACHT_ILLEGAL_ARGUMENT_EXCEPTION_HPP

#include <exceptions/krul_exception.hpp>

class IllegalArgumentException final : public KrulException
{
    public:
        explicit IllegalArgumentException(const std::string & reason) : KrulException("Illegal argument", reason) { }
};

#endif //CPP1_EINDOPDRACHT_ILLEGAL_ARGUMENT_EXCEPTION_HPP
