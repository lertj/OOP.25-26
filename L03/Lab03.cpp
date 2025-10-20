#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Student {
    char* studentName1;
    char* studentId1;
    float studentgrade1;
};


int main()
{
    /*char* studentName1 = new char[100];
    char* studentId1 = new char[15];
    float studentgrade1 = 0;

    char* studentName2 = new char[100];
    char* studentId2 = new char[15];
    float studentGrade2 = 0;

    char studentNames[100][100];
    char studentids[100][15];
    float studentGrades[100];*/

    Student s1;
    s1.studentgrade1 = 9.56;
    s1.studentId1 = new char[15];
    strcpy(s1.studentId1, "123456789");
    char name[] = "Alberto Montoya de la Rosa Ramirez Esteban the third";
    s1.studentName1 = new char[strlen(name)+1];
    strcpy(s1.studentName1, name);

    cout << s1.studentName1 << endl << s1.studentId1 << endl << s1.studentgrade1;


    return 0;
}
