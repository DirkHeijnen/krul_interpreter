#ifndef CPP1_KRUL_HTTPCLIENT_HPP
#define CPP1_KRUL_HTTPCLIENT_HPP

#include <curl/curl.h>
#include <memory>
#include "httpresponse.hpp"

class HttpClient
{
    public:
        HttpClient();
        HttpResponse get(const std::string& url);

    private:
        std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> curl { nullptr, curl_easy_cleanup };

        static size_t responseToString(void* contents, size_t size, size_t nmemb, std::string* s);
};

#endif //CPP1_KRUL_HTTPCLIENT_HPP
