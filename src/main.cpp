#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include "utils/SuperOutput.h"
#include <tr1/regex>
#include <string.h>

using namespace std;

enum State{VALID, INVALID};

const int ISBN_MAX_LENGTH = 13;
const char* EXAMPLE = "example";
const char* EXIT = "exit";

State checkDigits(SuperOutput * so, char * isbn)
{
    State state = VALID;

    for (int i = 0; i < ISBN_MAX_LENGTH; i++)
    {
        string character(1, *(isbn + i));
        so->print(character);

        if (i != ISBN_MAX_LENGTH - 1)
        {
            if (i == 1 || i == 5 || i == 11)
            {
                if (*(isbn + i) != '-')
                {
                    state = INVALID;
                }
            }
            else
            {
                if (((int)*(isbn + i) < 48 || (int)*(isbn + i) > 57))
                {
                    state = INVALID;
                }

            }
        }
        else
        {
            if (((int)*(isbn + i) < 48 || (int)*(isbn + i) > 57))
            {
                if (*(isbn + i) == 'X' || *(isbn + i) == 'x')
                {
                    state = VALID;
                }
            }
        }
    }
    return state;
}

State checkSum(char * isbn)
{
    int sum = 0;
    int j = 10;

    for (int i = 0; i < ISBN_MAX_LENGTH; i++)
    {
        if (i == 1 || i == 5 || i == 11)
        {
            continue;
        }
        else
        {
            if (*(isbn + i) == 'x' || *(isbn + i) == 'X')
            {
                sum += 10 * j;
                j--;
            }
            else
            {
                sum += ((int)*(isbn + i) - 48) * j;
                j--;
            }
        }
    }


    if (sum % 11 == 0)
    {
        return VALID;
    }
    else
    {
        return INVALID;
    }
}

void example(SuperOutput * so)
{
    char exampleISBNs[][13] = {
            {'1','-','2','1','4','-','0','2','0','3','1','-','3'},
            {'0','-','0','7','0','-','2','1','6','0','4','-','5'},
            {'2','-','1','4','-','2','4','1','2','4','2','-','4'},
            {'2','-','1','2','0','-','1','2','3','1','1','-','x'},
            {'0','-','5','3','4','-','9','5','2','0','7','-','x'},
            {'2','-','0','3','4','-','0','0','3','1','2','-','2'},
            {'1','-','0','1','3','-','1','0','2','0','1','-','2'},
            {'2','-','1','4','2','-','1','2','2','3'},
            {'3','-','0','0','1','-','0','0','0','0','a','-','4'}
    };
    for (int i = 0; i < 9; i++) {
        char *examplesPointer = exampleISBNs[i];
        if (checkDigits(so, examplesPointer) == VALID)
        {
            if (checkSum(examplesPointer) == VALID)
            {
                so->print(" <-- VALID");
            }
        }
        so->println();
    }
}

int main()
{
    int loop = 0;
    SuperOutput * so = new SuperOutput("output.txt");
    char ISBN[ISBN_MAX_LENGTH];
    char *pointerISBN = ISBN;
    example(so);

    while (loop != -1)
    {
        so->println("Please enter a valid ISBN (\"example\" to see examples, or \"exit\" to exit): ");
        cin.getline(pointerISBN, ISBN_MAX_LENGTH + 1);

        string test("example");

        loop = (strcmp(pointerISBN, EXAMPLE) == 0) ? 1 : (strcmp(pointerISBN, EXIT) == 0) ? -1 : 0;

        if (loop == 0)
        {
            if (checkDigits(so, pointerISBN) == VALID)
            {
                if (checkSum(pointerISBN) == VALID)
                {
                    so->println("That was a valid ISBN number");
                }
                else
                {
                    so->println("That was a valid ISBN format, but the checksum wasn't correct");
                }
            }
            else
            {
                so->println("That was not a valid ISBN format");
            }
        }
        else if (loop == 1)
        {
            example(so);
        }
    }
}