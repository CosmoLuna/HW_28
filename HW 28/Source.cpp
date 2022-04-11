#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T> void showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
template <typename T> void fillArr(T arr[], int length, int min = 0, int max = 10) {
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}

template <typename T> T* resizeArr(T arr[], int length1, int length2) {
	T* newArr = new T[length2];
	for (int i = 0; i < length2; i++)
		newArr[i] = arr[i];
	delete[] arr;
	return newArr;
}

int main() {
	setlocale(LC_ALL, "Russian");

	// Задача 1
	unsigned int n, m;
	cout << "Задача 1\nВведите длины массивов: ";
	cin >> n >> m;
	int* A = new int[n];
	int* B = new int[m];

	fillArr(A, n);
	fillArr(B, m);

	cout << "Массив А: " << endl;
	showArr(A, n);
	cout << endl << "Массив В: " << endl;
	showArr(B, m);
	
	int* C = new int[n + m];
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = n; i < n + m; i++)
		C[i] = B[i - n];

	cout << endl << "Массив C: " << endl;
	showArr(C, n + m);

	delete[] A;
	delete[] B;

	// Задача 2
	unsigned int L = 5;
	int* Arr = new int[L];
	fillArr(Arr, L);
	cout << "\nЗадача 2\nМассив Arr:\n";
	showArr(Arr, L);
	Arr = resizeArr(Arr, L, 10);
	fillArr(Arr, 10);
	showArr(Arr, 10);
	delete[] Arr;

	return 0;
}