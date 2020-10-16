#ifndef CPP1_EINDOPDRACHT_NO_SUCH_METHOD_EXCEPTION_HPP
#define CPP1_EINDOPDRACHT_NO_SUCH_METHOD_EXCEPTION_HPP

#include <exceptions/krul_exception.hpp>

class NoSuchMethodException final : public KrulException
{
    public:
        explicit NoSuchMethodException(const std::string & reason) : KrulException("Method was not found", reason) { }
};

#endif //CPP1_EINDOPDRACHT_NO_SUCH_METHOD_EXCEPTION_HPP
