#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void remove_vowels(const string& s, string& t)
{
    int i, j = 0;
    char* temp = new char[s.size() + 1];
    strcpy(temp, "");

    for (i = 0; s[i] != '\0'; i++)
    {
        char c = tolower(s[i]);
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
        {
            //temp[j] = s[i];
            strncat(temp, s.c_str()+i,1);

            j++;
        }
    }
    temp[j] = '\0';
    t = temp;
    delete[] temp;
}

int main()
{
    string s, t;
    cout << "enter a string: ";
    getline(cin, s);
    remove_vowels(s, t);
    cout << "String without vowels: " << t << endl;
    return 0;
}
