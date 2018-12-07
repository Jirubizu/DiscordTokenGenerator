#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "sleepy_discord/websocketpp_websocket.h";

static const char alphanum[] =
"0123456789"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"_";

static int stringLength = sizeof(alphanum) - 1;

struct Response {
    int32_t statusCode;
    std::string text;
    std::map<std::string, std::string> header;
};


class Bot : public SleepyDiscord::DiscordClient{
public:
    using SleepyDiscord::DiscordClient::DiscordClient;
};

char generateRandomString(int stringLen)  // Random string generator function.
{
    return alphanum[rand() % stringLen];
}
void generateToken(int quantity){
    std::ofstream tokensfile ("tokens.txt");
    if (tokensfile.is_open()){
        std::string token, randomChar;
        for (int i=0; i<quantity;i++){
            for(int z=0; z < 59; z++)
            {
                if (z == 24 || z == 31){
                    token.append(".");
                }else if(z > 31){
                    randomChar = generateRandomString(stringLength);
                    token.append(randomChar);
                }else{
                    randomChar = generateRandomString(stringLength-1);
                    token.append(randomChar);
                }
            }
            Bot(token,2);
            tokensfile << token << "\n";
            token.clear();
        }
        tokensfile.close();
    }else{
        std::cout << "Unable to open file";
    }


}

int main()
{
    generateToken(1);
    return 0;

}
