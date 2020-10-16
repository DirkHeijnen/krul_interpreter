#ifndef CPP1_EINDOPDRACHT_NO_SUCH_FIELD_EXCEPTION_HPP
#define CPP1_EINDOPDRACHT_NO_SUCH_FIELD_EXCEPTION_HPP

#include <exceptions/krul_exception.hpp>

class NoSuchFieldException final : public KrulException
{
    public:
        explicit NoSuchFieldException(const std::string& reason) : KrulException("Field was not found", reason) { }
};

#endif //CPP1_EINDOPDRACHT_NO_SUCH_FIELD_EXCEPTION_HPP
