// PB 3 - binary and decimal digits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

using namespace std;

int checkNumberSystem(char* s)
{
    int i = 0;
    bool ok2 = 1, ok4 = 1, ok8 = 1, ok10 = 1, ok16 = 1;

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] != '0' || s[i] != '1')
            ok2 = 0;

        if (s[i] < '0' || s[i] > '3')
            ok4 = 0;

        if (s[i] < '0' || s[i] > '7')
            ok8 = 0;

        if (s[i] < '0' || s[i] > '9')
            ok10 = 0;

        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f')))
            ok16 = 0;
    }
    if (ok2 == 1)
        return 2;
    if (ok4 == 1)
        return 4;
    if (ok8 == 1)
        return 8;
    if (ok10 == 1)
        return 10;
    if (ok16 == 1)
        return 16;

    return -1;
}

int main()
{
    cout << "Insert string: ";
    char* string = (char*)malloc(100 * sizeof(char));
    cin.getline(string, 100);
    cout << endl;

    cout << "The number system is: " << checkNumberSystem(string);

    free(string);

    return 0;
}
