//ex 4-vector of frquency for letters,turn the no of frequency into stars

#include<iostream>
#include<string>
using namespace std;

void frequency(const string& s)
{
	char freq[26] = { 0 };
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (islower(s[i]))
		{
			freq[s[i] - 'a']++;
		}
	}
	//now we print the numbers
	for (int i = 0; i < 26; i++)
	{
		if (freq[i] > 0)
		{
			cout << char('a' + i) << ":";

		}
		for (int j = 0; j < freq[i]; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

int main() {
	string text;
	cout << "Enter a string: ";
	getline(cin, text);
	frequency(text);
	return 0;
}