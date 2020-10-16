#ifndef CPP1_KRUL_HTTPCLIENT_HPP
#define CPP1_KRUL_HTTPCLIENT_HPP

#include "httpresponse.hpp"

class HttpClient
{
    public:
        HttpResponse get(const std::string& url);

    private:
        static size_t responseToString(void* contents, size_t size, size_t nmemb, std::string* s);
};

#endif //CPP1_KRUL_HTTPCLIENT_HPP
