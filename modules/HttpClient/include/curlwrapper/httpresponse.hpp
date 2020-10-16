#ifndef CPP1_KRUL_HTTPRESPONSE_HPP
#define CPP1_KRUL_HTTPRESPONSE_HPP

#include <string>
#include "httpstatuscode.hpp"

class HttpResponse
{
    public:

        HttpResponse(HttpStatusCode statusCode, const std::string &responseBody)
        {
            this->statusCode = statusCode;
            this->body = responseBody;
        }

    public:
        HttpStatusCode statusCode;
        std::string body;
};

#endif //CPP1_KRUL_HTTPRESPONSE_HPP
