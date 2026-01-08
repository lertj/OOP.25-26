#include<iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "test";
    ofstream fout("Out.txt", ios::binary);
    /*fout << "Test";
    fout << 5;*/

    ifstream fin("In.txt");
    string something = "";
    char* buffer = new char[5000];
    fin.getline(buffer, 100);
    /*fin >> something;*/
    fout << something;
    cout << buffer;

    cout << "\n\n\n";

    //while (fin.getline(buffer, 5000)) { // when EOF is reached this condition will be evaluated as false
    //  fout << buffer;
    //  fout << "\n";
    //}
    int x = 9;
    fout.write((char*)&x, sizeof(x));

    fin.close();
    fout.close();


    return 0;
}
