#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

static const char alphanum[] =
"0123456789"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"_";

char generateRandomString(int stringLen)  // Random string generator function.
{
    return alphanum[rand() % stringLen];
}

void generateToken(int quantity){
    std::ofstream tokensfile ("tokens.txt");
    if (tokensfile.is_open()){ //while the txt is open
        std::string token, randomChar;
        for (int i=0; i<quantity;i++){
            for(int z=0; z < 59; z++)
            {
                if (z == 24 || z == 31){
                    token.append(".");
                }else if(z > 31){
                    randomChar = generateRandomString(sizeof(alphanum) - 1);
                    token.append(randomChar);
                }else{
                    randomChar = generateRandomString(sizeof(alphanum) - 2);
                    token.append(randomChar);
                }
            }
            tokensfile << token << "\n";
            token.clear();
        }
        tokensfile.close();
    }else{ //err
        std::cout << "Unable to open file";
    }//
}

int main()
{ //
    int amount;
    std::cout << "How many tokens would you like to generate?\n>> ";std::cin >> amount;
    generateToken(amount);
    return 0;
} //
