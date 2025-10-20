#include <iostream>

using namespace std;

void fct(int* &v , int& nr, int x, int i) {
	int* newvector;
	newvector = new int[++nr];
	for (int p = 0; p < nr; p++) {
		newvector[p] = v[p];
	}
	for (int j = nr; j > i; j--) {
		newvector[j] = newvector[j - 1];
	}
	
	newvector[i] = x;
	v = newvector;

}

int main() {

	int nr, i, x;
	nr = 4;
	int* vector;
	vector = new int[nr];
	vector[0] = 0;
	vector[1] = 1;
	vector[2] = 2;
	vector[3] = 3;
	std::cout << "What number: ";
	std::cin >> x;
	std::cout << "What position: ";
	std::cin >> i;
	fct(vector, nr, x, i);

	for (int j = 0; j < nr; j++) {
		printf("%d", vector[j]);
	}

	return 0;
}