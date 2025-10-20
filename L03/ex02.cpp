#include<iostream>
using namespace std;


void Countwords(char* s)
{
	int word = 0, count = 0, pos = 0, c;
	int start = 0;
	while (s[pos] != '\0')
	{
		c = s[pos];
		if (c != ' ' && c != '.' && word == 0)
		{
			count++;
			word = 1;
		}

		else if (c == ' ')
		{
			word = 0;
		}

		else if (c == '.')
		{
			for (int i = start; i < pos; i++)
			{
				cout << s[i];
			}
			cout << ' ' << '.' << count << '\n';
			count = 0;
			word = 0;
			start = pos + 1;
		}
		pos++;
	}


}




int main()
{
	char* s = new char[100];
	cin.getline(s, 100);

	Countwords(s);

	delete[] s;
	return 0;
}