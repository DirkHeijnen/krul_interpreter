#include "curlwrapper/httpclient.hpp"

#include <curl/curl.h>
#include <memory>

HttpResponse HttpClient::get(const std::string &url)
{
    std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> curl(curl_easy_init(), curl_easy_cleanup);

    // Response containers
    std::string responseBody;
    char* contentType;
    long statusCode = 0;

    // Setup the request
    curl_easy_setopt(curl.get(), CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl.get(), CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1);
    curl_easy_setopt(curl.get(), CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curl.get(), CURLOPT_HTTPGET, true);
    curl_easy_setopt(curl.get(), CURLOPT_USERAGENT, "libcurl-agent/1.0");
    curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, responseToString);
    curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &responseBody);

    // Perform the request
    curl_easy_perform(curl.get());

    // Get data from the result
    curl_easy_getinfo(curl.get(), CURLINFO_CONTENT_TYPE, &contentType);
    curl_easy_getinfo (curl.get(), CURLINFO_RESPONSE_CODE, &statusCode);

    return HttpResponse(HttpStatusCode(statusCode), responseBody);
}

size_t HttpClient::responseToString(void* contents, size_t size, size_t nmemb, std::string *s)
{
    size_t newLength = size*nmemb;
    s->append((char*)contents, newLength);
    return newLength;
}
