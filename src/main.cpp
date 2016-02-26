#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include "utils/SuperOutput.h"

using namespace std;

const int ISBN_MAX_LENGTH = 13;
const int EXAMPLE = -1;
const int EXIT_PROGRAM = -2;

char * input(SuperOutput * so)
{
    while (true)
    {
        char input[ISBN_MAX_LENGTH];

        so->println("Please enter a valid ISBN: ");
        cin.getline(input, ISBN_MAX_LENGTH) >> input;
        //if (input == EXAMPLE)
        {

        }
    }
}

void example(SuperOutput * so)
{
    // TODO
}

bool checkDigits(char * isbn)
{
    // TODO
}

bool checkSum(char * isbn)
{
    // TODO
}

int main()
{
    SuperOutput * so = new SuperOutput("output.txt");
    char name[3];
    cin.getline(name, 4);
    for (int i = 0; i < sizeof(name); i++)
    {
        char s = (char) name[i];
        so->println(s);
    }
}