// #include <crtdbg.h>

#include <iostream>
#include <string>

#include "Krul.hpp"
#include "HttpClient.hpp"

void writeBanner(int challengeNumber, const std::string& url)
{
    std::cout << "///////////////////////////////////////////////////" << std::endl;
    std::cout << "//////                                      ///////" << std::endl;
    std::cout << "//////            CHALLENGE " << challengeNumber << "               ///////" << std::endl;
    std::cout << "//////                                      ///////" << std::endl;
    std::cout << "///////////////////////////////////////////////////" << std::endl;
    std::cout << "URL: " << url << std::endl;
}

KrulProgram doChallenge(const std::string& fileName, int num, HttpClient& client)
{
    const std::string baseUrl = "https://student.aii.avans.nl/doc/rpbpolis1/cpp1/";
    HttpResponse response = client.get(baseUrl + fileName);

    KrulProgram krul = KrulProgram();
    writeBanner(num, baseUrl + fileName);
    krul.load(response.body);
    krul.execute();

    if (krul.isFinished)
    {
        std::cout << "Solution: " << krul.memory.stack->readString() << std::endl << std::endl;
    }
    else
    {
        std::cout << "Next file url: " << krul.memory.stack->readString() << std::endl << std::endl;
    }

    return krul;
}

int main(int argc, char* argv[])
{
    try
    {
        HttpClient client = HttpClient();

        int challenge = 1;
        std::string fileName = "start.txt";
        KrulProgram program = doChallenge(fileName, challenge, client);

        while (!program.isFinished)
        {
            challenge++;
            fileName = program.memory.stack->readString();
            program = doChallenge(fileName, challenge, client);
        }
    }
    catch (KrulException& e)
    {
        std::cout << "Caught error: " << e.getMessage() << " : " << e.getReason() << std::endl;
    }


    // _CrtDumpMemoryLeaks();
    return 0;
}