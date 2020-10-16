#ifndef CPP1_EINDOPDRACHT_KRUL_EXCEPTION_HPP
#define CPP1_EINDOPDRACHT_KRUL_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class KrulException : public std::runtime_error
{
    public:
        KrulException(const std::string &message, const std::string &reason)
                : runtime_error(message), message(message), reason(reason) { }

        const std::string getReason() const
        {
            return this->reason;
        }

        const std::string getMessage() const
        {
            return this->message;
        }

    private:
        std::string message;
        std::string reason;
};

#endif //CPP1_EINDOPDRACHT_KRUL_EXCEPTION_HPP
