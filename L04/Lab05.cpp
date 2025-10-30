#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

//struct BookStr {
//	char* title;
//	char* author;
//	int year;
//};

class Book {
private: //by default
	string isbn;
	char* title = nullptr;
public:
	
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

	/*Book() {

	}*/

	Book(const char* title, const char* author, const int year) {
		cout << "\nHey, I am a constructor with parameters!\n";
		this->title = new char[strlen(title) +1];
		strcpy(this->title, title);
		//author = new char[50]; // shadowing // wrong
		this->author = new char[50];
		strcpy(this->author, author);
		this->year = year;
	}

	Book(const char* title, const char* author, const int year, string isbn) {
		cout << "\nHey, I am a constructor with parameters!\n";
		this->title = new char[strlen(title) +1];
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

	string getIsbn() {
		return this->isbn;
	}

	void setIsbn(string isbn) {
		if (isbn.size() < 12) {
			cout << "The ISBN is not valid.";
			return;
		}
		this->isbn = isbn;
	}

	char* getTitle() {
		//return this->title; // NEVER NO NO // shallow copy

		char* copyTitle = new char[strlen(this->title) + 1]; // allocate
		strcpy(copyTitle, this->title); // copy // deep copy

		return copyTitle;

	}

	void setTitle(char* title) {
		// this->title = title; // NO NO // shallow copy

		if (this->title != nullptr) {
			delete[] this->title;
		}

		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
	}
};

int main() {
	/*Book* books = new Book[10];
	books[2].author;*/
	//Book actualBook;
	////cout << actualBook.title << endl << actualBook.author << endl << actualBook.year<<endl;
	//actualBook.display();
	////actualBook.title = new char[50];
	//actualBook.author = new char[50];
	////strcpy(actualBook.title, "Morometii");
	//strcpy(actualBook.author, "Marin Preda");
	////cout << actualBook.title << endl << actualBook.author << endl << actualBook.year << endl;
	//actualBook.display();

	////actualBook.title[0] = 'P';
	////cout << actualBook.title << endl << actualBook.author << endl << actualBook.year << endl;
	//actualBook.display();

	Book actualBook2("Ion","Rebreanu", 1930);
	//cout << actualBook2.title << endl << actualBook2.author << endl << actualBook2.year << endl;
	actualBook2.display();

	Book actualBook3("Ion", "Rebreanu", 1930,"0251-2661-2377");
	actualBook3.display();

	cout << "\n\n\n";

	cout << "Book ISBN is: " << actualBook3.getIsbn();

	cout << "\nSetting the ISBN...\n";
	actualBook3.setIsbn("1234-5678-9101");
	cout << "Book ISBN is: " << actualBook3.getIsbn();

	/*BookStr bookS;
	bookS.author;
	bookS.title;

	BookStr* pBook = &bookS;
	pBook->author;*/

	cout << "\n\n\n";
	char* myTitle = actualBook3.getTitle();
	cout << "Book Title is: " << myTitle;
	myTitle[0] = 'K';
	actualBook3.display();

	cout << "\nSetting the Title...\n";
	char* newTitle = new char[50];
	strcpy(newTitle, "Abcdefg");
	actualBook3.setTitle(newTitle);
	cout << endl;
	actualBook3.display();

	//...
	newTitle[0] = ';';

	actualBook3.display();
	
	return 0;
}