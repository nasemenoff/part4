// part4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void fillMatrix(int **matrix, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = rand() % 100 + 1;
		}
	}
}

void printMatrix(int **matrix, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int* getMinVector(int **matrix, int N, bool byRows) {
	int *vector = new int[N];
	for (int i = 0; i < N; i++) {
		int min = INT_MAX;
		for (int j = 0; j < N; j++) {
			int m = byRows ? matrix[i][j] : matrix[j][i];
			if (m < min) {
				min = m;
			}
		}
		vector[i] = min;
	}
	return vector;
}

int* getMaxVector(int **matrix, int N, bool byRows) {
	int *vector = new int[N];
	for (int i = 0; i < N; i++) {
		int max = INT_MIN;
		for (int j = 0; j < N; j++) {
			int m = byRows ? matrix[i][j] : matrix[j][i];
			if (m > max) {
				max = m;
			}
		}
		vector[i] = max;
	}
	return vector;
}

double average(const int *vector, int N) {
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += vector[i] * 1.0; //умножаю на 1.0 для преобразования в double
	}
	return sum / N;
}

int* getVectorMaxMinusMin(int **matrix, int N) {
	int *vector = new int[N];
	const int *vectorMin = getMinVector(matrix, N, 1);
	const int *vectorMax = getMaxVector(matrix, N, 1);
	for (int i = 0; i < N; i++) {
		vector[i] = vectorMax[i] - vectorMin[i];
	}
	delete[] vectorMin;
	delete[] vectorMax;
	return vector;
}

int getNumberOfLineWithMinValue(const int *vector, int N) {
	int lineNumber = 0;
	int min = INT_MAX;
	for (int i = 0; i < N; i++) {
		if (vector[i] < min) {
			min = vector[i];
			lineNumber = i;
		}
	}
	return lineNumber;
}

int getNumberOfLineWithMaxValue(const int *vector, int N) {
	int lineNumber = 0;
	int max = INT_MIN;
	for (int i = 0; i < N; i++) {
		if (vector[i] > max) {
			max = vector[i];
			lineNumber = i;
		}
	}
	return lineNumber;
}

void changeRowsMinMax(int **matrix, int N) {
	const int rowMin = getNumberOfLineWithMinValue(getMinVector(matrix, N, 1), N);
	const int rowMax = getNumberOfLineWithMaxValue(getMaxVector(matrix, N, 1), N);
	int *tempRow = new int[N];
	for (int i = 0; i < N; i++) {
		tempRow[i] = matrix[rowMin][i];
	}
	for (int i = 0; i < N; i++) {
		matrix[rowMin][i] = matrix[rowMax][i];
		matrix[rowMax][i] = tempRow[i];
	}
	delete[] tempRow;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "russian");
	int N;
	do {
		cout << "Введите размерность матрицы N <= 10\n";
		cin >> N;
		if (N < 1 || N > 10) {
			cout << "Неправильная размерность, попробуйте еще раз\n";
		}
	} while (N < 1 || N > 10);

	int **A = new int* [N]; //массив из N указателей
	for (int i = 0; i < N; i++) {
		A[i] = new int[N];
	}
	fillMatrix(A, N);
	printMatrix(A, N);

	//26
	const int *vectorMin = getMinVector(A, N, 1);
	cout << "Вектор из наименьших значений: ";
	for (int i = 0; i < N; i++) {
		cout << vectorMin[i] << " ";
	}
	cout << "\nСреднее арифметическое элементов вектора = " << average(vectorMin, N);
	delete[] vectorMin;

	//27
	const int *vectorMaxMinusMin = getVectorMaxMinusMin(A, N);
	cout << "\nВектор из разностей наибольших и наименьших значений элементов строк: ";
	for (int i = 0; i < N; i++) {
		cout << vectorMaxMinusMin[i] << " ";
	}
	delete[] vectorMaxMinusMin;

	//28
	const int *vectorMinByRows = getMinVector(A, N, 1);
	const int rowNumber = getNumberOfLineWithMinValue(vectorMinByRows, N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[rowNumber][i];
	}
	cout << "\nСумма элементов строки, в которой расположен наименьший элемент = " << sum;
	delete[] vectorMinByRows;

	//29
	const int *vectorMinByCols = getMinVector(A, N, 0);
	const int colNumber = getNumberOfLineWithMinValue(vectorMinByCols, N);
	sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i][colNumber];
	}
	cout << "\nСумма элементов столбца, в котором расположен наименьший элемент = " << sum << endl;
	delete[] vectorMinByCols;

	//30
	changeRowsMinMax(A, N);
	cout << "Исходная матрица после смены местами строки, содержащей максимальный элемент, со строкой, содержащей минимальный элемент\n";
	printMatrix(A, N);

	for (int i = 0; i < N; i++) {
		delete[] A[i];
	}
	delete[] A;
	return 0;
}

