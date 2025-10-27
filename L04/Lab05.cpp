#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

//struct Book {
//	char* title;
//	char* author;
//	int year;
//};

class Book {
private: //by default
	string isbn;
public:
	char* title = nullptr;
	char* author = nullptr;
	int year;

	Book() {
		cout << "\nHey, I am the default constructor!\n";
		this->title = new char[50];
		this->author = new char[50];
		strcpy(this->title, "-");
		strcpy(this->author, "-");
		this->isbn = "-";
		this->year = -1;
	}

	Book(const char* title, const char* author, const int year) {
		cout << "\nHey, I am a constructor with parameters!\n";
		this->title = new char[strlen(title)];
		strcpy(this->title, title);
		//author = new char[50]; // shadowing // wrong
		this->author = new char[50];
		strcpy(this->author, author);
		this->year = year;
	}

	Book(const char* title, const char* author, const int year, string isbn) {
		cout << "\nHey, I am a constructor with parameters!\n";
		this->title = new char[strlen(title)];
		strcpy(this->title, title);
		//author = new char[50]; // shadowing // wrong
		this->author = new char[50];
		strcpy(this->author, author);
		this->year = year;
		this->isbn = isbn;
	}

	void display() {
		cout << "Title: " << this->title << endl;
		cout << "Author: " << this->author << endl;
		cout << "ISBN: " << this->isbn << endl;
		cout << "Year: " << this->year << endl;
	}
};

int main() {
	/*Book* books = new Book[10];
	books[2].author;*/
	Book actualBook;
	//cout << actualBook.title << endl << actualBook.author << endl << actualBook.year<<endl;
	actualBook.display();
	actualBook.title = new char[50];
	actualBook.author = new char[50];
	strcpy(actualBook.title, "Morometii");
	strcpy(actualBook.author, "Marin Preda");
	//cout << actualBook.title << endl << actualBook.author << endl << actualBook.year << endl;
	actualBook.display();

	actualBook.title[0] = 'P';
	//cout << actualBook.title << endl << actualBook.author << endl << actualBook.year << endl;
	actualBook.display();

	Book actualBook2("Ion","Rebreanu", 1930);
	//cout << actualBook2.title << endl << actualBook2.author << endl << actualBook2.year << endl;
	actualBook2.display();

	Book actualBook3("Ion", "Rebreanu", 1930,"0251-2661-2377");
	actualBook3.display();
	return 0;
}