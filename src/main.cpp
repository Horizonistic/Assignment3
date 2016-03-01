#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include "utils/SuperOutput.h"
#include <tr1/regex>

using namespace std;

enum State{VALID, INVALID};

const int ISBN_MAX_LENGTH = 13;
const int EXAMPLE = -1;
const int EXIT_PROGRAM = -2;

State checkDigits(char * isbn)
{
    State state = VALID;

    for (int i = 0; i < ISBN_MAX_LENGTH; i++)
    {
        cout<<*(isbn + i);

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
    cout<<endl;
    if (state == VALID)
    {
        return VALID;
    }
    else
    {
        return INVALID;
    }
}

State checkSum(char * isbn)
{
    // TODO
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
        State state = INVALID;
        char *examplesPointer = exampleISBNs[i];
        state = checkDigits(examplesPointer);
        if (state == VALID)
        {
            cout<<"TRUE"<<endl;
        }
    }
}

int main()
{
    State state = INVALID;
    SuperOutput * so = new SuperOutput("output.txt");
    char ISBN[ISBN_MAX_LENGTH];
    char *pointerISBN = ISBN;
    example(so);
/*
    so->println("Please enter a valid ISBN: ");
    //cin.getline(pointerISBN, ISBN_MAX_LENGTH + 1);

    for (int i = 0; i < ISBN_MAX_LENGTH; i++)
    {
        *(pointerISBN + i) = (char) (i + 97);
    }

    state = checkDigits(pointerISBN);

    if (state == VALID)
    {
        for (int i = 0; i < ISBN_MAX_LENGTH; i++)
        {
            cout << *(pointerISBN + i) << endl;
        }
    }
    */
}