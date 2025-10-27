#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
int** inmultire(int** matr1, int** matr2, int n, int m, int k, int t)
{
	int** matr3 = new int* [n];
	for (int i = 0; i < n; i++)
		matr3[i] = new int[t];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < t; j++)
			matr3[i][j] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < t; j++)
			for (int of = 0; of < m; of++)
				matr3[i][j] += matr1[i][of] * matr2[of][j];
	return matr3;
}

int main()
{
	int n, m, k, t, i, j;
	cout << "Introduceti nr de linii si de coloane pentru prima matrice: ";
	cin >> n >> m;
	cout << "Introduceti nr de linii si de coloane pentru a doua matrice: ";
	cin >> k >> t;
	if (m != k)
	{
		cout << "Nr de coloane al primei matrici trebuie sa fie egal cu nr de linii a celei de a doua, modificati: ";
		return 1;
	}

	int** matr1 = new int* [n];
	for (i = 0; i < n; i++)
		matr1[i] = new int[m];

	int** matr2 = new int* [k];
	for (i = 0; i < k; i++)
		matr2[i] = new int[t];


	cout << "Scrieti prima matrice " << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> matr1[i][j];


	cout << "Scrieti a doua matrice " << endl;
	for (i = 0; i < k; i++)
		for (j = 0; j < t; j++)
			cin >> matr2[i][j];

	cout << endl;

	int** matr3 = inmultire(matr1, matr2, n, m, k, t);

	for (i = 0; i < n; i++) {
		for (j = 0; j < t; j++)
			cout << matr3[i][j] << " ";
		cout << endl;
	}

	for (i = 0; i < n; i++)
		delete[] matr1[i];
	delete[] matr1;

	for (i = 0; i < k; i++)
		delete[] matr2[i];
	delete[] matr2;

	for (i = 0; i < n; i++)
		delete[] matr3[i];
	delete[] matr3;


	return 0;
}