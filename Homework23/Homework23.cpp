#include <iostream>

using namespace std;

void threeMax(int& refA, int& refB, int& refC);
int& returnFirstNegative(int array[], int length);
void makeElementsNull(int * array1[], int length1, int * array2[], int length2);
void showArray(int * pArray[], int length);

int main() {
	setlocale(LC_ALL, "Russian");

	//Задача 1

	cout << "Задача 1.\n";
	int a = 3, b = 5, c = 4;
	threeMax(a, b, c);
	cout << a << " " << b << " " << c << endl;

	// Задача 2

	cout << "\nЗадача 2.\n";
	int array[5] = { 2, 3, -1, 0, 5 };
	cout << &returnFirstNegative(array, 5) << endl;
	
	// Задача 3

	cout << "\nЗадача 3.\n";

	int array1[7] = { 3, 6, 4, 1, 4, 8, 2 };
	int array2[6] = { 5, 3, 1, 5, 10, 8 };
	int* pArray1 = &array1[0];
	int* pArray2 = &array2[0];
	cout << "Массив 1:\n";
	showArray(&pArray1, 7);

	cout << "\nМассив 2:\n";
	showArray(&pArray2, 6);

	makeElementsNull(&pArray1, 7, &pArray2, 6);

	cout << "\nМассив 2 после работы функции:\n";
	showArray(&pArray2, 6);

	return 0;
}

// Задача 3

void makeElementsNull(int * pArray1[], int length1, int * pArray2[], int length2) {
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++) {
			if (*(pArray1 + i) == *(pArray2 + j))
				*(pArray2 + j) = 0;
		}
	}
}

void showArray(int * pArray[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << pArray[i] << ", ";
	cout << "\b\b]\n";
}

// Задача 2

int& returnFirstNegative(int array[], int length) {
	int iNeg = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] < 0)
			return i;
	}
	return array[iNeg];
}


// Задача 1

void threeMax(int& refA, int& refB, int& refC) {
	if (refA > refB && refA > refC) {
		refB = refA;
		refC = refA;
	}
	
	if (refB > refA && refB > refC) {
		refA = refB;
		refC = refB;
	}

	if (refC > refA && refC > refB) {
		refA = refC;
		refB = refC;
	}
}