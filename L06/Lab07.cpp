#include <iostream>

using namespace std;

class Employee {
	const string name;
	int ageWithinCompany;
	char* title = nullptr;
	int* salaryHistory = nullptr;
	int noSalaryChanges = 0;
public:
	static int MIN_SALARY;
				// ATTRIBUTE_NAME(VALUE/PARAMETER_NAME)
	Employee() : name("Odobasian"),ageWithinCompany(0), title(nullptr), salaryHistory(nullptr), noSalaryChanges(0) {
		//this->name = "Odobasian"; // error because name is constant
		//this->ageWithinCompany = 0;
		//this->title = nullptr;
		//this->salaryHistory = nullptr;
		//this->noSalaryChanges = 0;
	}
																				// ATTRIBUTE_NAME(VALUE/PARAMETER_NAME)
	Employee(string _name, int ageWithinTheCompany, const char* title, int* salaryHistory, int noSalaryChanges) : name(_name) {
		//this->name = name;
		//ageWithinCompany = ageWithinTheCompany; // shadowing
		this->ageWithinCompany = ageWithinTheCompany;

		this->title = new char[strlen(title) + 1];
		strcpy_s(this->title, strlen(title)+1, title);

		this->salaryHistory = new int[noSalaryChanges];
		this->noSalaryChanges = noSalaryChanges;
		for (int i = 0; i < noSalaryChanges; i++) {
			this->salaryHistory[i] = salaryHistory[i];
		}
	}

	int* getSalaryHistory() {
		int* copy = new int[this->noSalaryChanges];
		for (int i = 0; i < noSalaryChanges; i++) {
			copy[i] = this->salaryHistory[i];
		}

		return copy;
	}

	void setSalaryHistory(int* salaryHistory, int noSalaryChanges) {

		if (salaryHistory == nullptr || noSalaryChanges < 1) {
			cout << "Not a valid array!\n";
			throw new exception("Not a valid array!");
			return;
		}

		if (this->salaryHistory != nullptr) {
			delete[] this->salaryHistory;
		}

		this->noSalaryChanges = noSalaryChanges;
		//this->salaryHistory = salaryHistory; // shallow copy
		this->salaryHistory = new int[noSalaryChanges];

		for (int i = 0; i < noSalaryChanges; i++) {
			this->salaryHistory[i] = salaryHistory[i];
		}

		this->MIN_SALARY++;
	}

	void display() {
		cout << "Name: " << this->name << endl;
		cout << "Title: " << this->title << endl;
		cout << "No salary changes: " << this->noSalaryChanges << endl;;
		cout << "Salary history: ";
		for (int i = 0; i < this->noSalaryChanges; i++) {
			cout << this->salaryHistory[i] << ' ';
		}
		cout << "MIN_SALARY: " << this->MIN_SALARY; // not recommended
	}

	void emptyStuff() {
		delete[] salaryHistory;
		this->salaryHistory = nullptr;
		delete[] title;
		this->title = nullptr;
	}

	~Employee() {
		if(salaryHistory != nullptr){
			delete[] salaryHistory;
			this->salaryHistory = nullptr;
		}
		if (title != nullptr) {
			delete[] title;
			this->title = nullptr;
		}
	}
};

int Employee::MIN_SALARY = 2300;

int main() {
	//string name = "Balaurentiu";
	Employee e1("Balaurentiu", 3, "Manager", new int[3] {3000, 3500, 4000}, 3);
	e1.display();

	e1.setSalaryHistory(new int[4] {3000, 3500, 4000, 5000}, 4);
	e1.display();

	Employee e2("Mihai", 3, "Developer", new int[3] {3000, 3500, 4000}, 3);
	e2.display();
	e2.setSalaryHistory(new int[4] {3000, 3500, 4000, 5000}, 4);
	e1.display();
	e2.display();

	cout <<endl << "MIN_SALARY: " << Employee::MIN_SALARY;

	//e1.getSalaryHistory(); // memory leak
	int* copy = e1.getSalaryHistory(); // memory leak
	delete[] copy;

	Employee e3;
	e2.emptyStuff();
	return 0;
}