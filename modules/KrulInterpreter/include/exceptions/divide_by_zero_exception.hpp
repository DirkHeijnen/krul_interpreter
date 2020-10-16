#ifndef CPP1_EINDOPDRACHT_DIVIDE_BY_ZERO_EXCEPTION_HPP
#define CPP1_EINDOPDRACHT_DIVIDE_BY_ZERO_EXCEPTION_HPP

#include <exceptions/krul_exception.hpp>

class DivideByZeroException final : public KrulException
{
    public:
        explicit DivideByZeroException(const std::string& reason) : KrulException("Divide by zero error", reason) { }
};

#endif //CPP1_EINDOPDRACHT_DIVIDE_BY_ZERO_EXCEPTION_HPP
