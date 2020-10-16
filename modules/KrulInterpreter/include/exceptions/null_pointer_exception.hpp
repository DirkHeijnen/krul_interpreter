#ifndef CPP1_EINDOPDRACHT_NULL_POINTER_EXCEPTION_HPP
#define CPP1_EINDOPDRACHT_NULL_POINTER_EXCEPTION_HPP

#include <exceptions/krul_exception.hpp>

class NullPointerException final : public KrulException
{
    public:
        explicit NullPointerException(const std::string& message, const std::string & reason) : KrulException(message, reason) { }
};

#endif //CPP1_EINDOPDRACHT_NULL_POINTER_EXCEPTION_HPP
