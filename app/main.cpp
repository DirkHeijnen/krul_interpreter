#include <iostream>
#include <string>

#include <Krul.hpp>
#include <HttpClient.hpp>

void writeBanner(int challengeNumber, const std::string& url)
{
    std::cout << "///////////////////////////////////////////////////" << std::endl;
    std::cout << "//////                                      ///////" << std::endl;
    std::cout << "//////            CHALLENGE " << challengeNumber << "               ///////" << std::endl;
    std::cout << "//////                                      ///////" << std::endl;
    std::cout << "///////////////////////////////////////////////////" << std::endl;
    std::cout << "URL: " << url << std::endl << std::endl;
}

KrulProgram doChallenge(const std::string& fileName, int num)
{
    HttpClient client = HttpClient();
    const std::string baseUrl = "https://student.aii.avans.nl/doc/rpbpolis1/cpp1/";
    HttpResponse response = client.get(baseUrl + fileName);

    KrulProgram krul = KrulProgram();
    writeBanner(num, baseUrl + fileName);
    krul.load(response.body);
    krul.execute();

    std::cout << std::endl << "Solution: " << krul.memory.stack->readString() << std::endl << std::endl << std::endl;

    return krul;
}

int main(int argc, char* argv[])
{
    try
    {
        int challenge = 0;
        std::string fileName = "start.txt";

        KrulProgram program = doChallenge(fileName, challenge);
        while (!program.isFinished)
        {
            challenge++;
            fileName = program.memory.stack->readString();
            program = doChallenge(fileName, challenge);
        }

        std::cout << "You're finished!" << std::endl;
    }
    catch (KrulException& e)
    {
        std::cout << "Caught error: " << e.getMessage() << " : " << e.getReason() << std::endl;
    }

    return 0;
}