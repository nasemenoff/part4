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

int* getMinVectorByRows(int **matrix, int N) {
	int *vector = new int[N];
	for (int i = 0; i < N; i++) {
		int min = INT_MAX;
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
		vector[i] = min;
	}
	return vector;
}

int* getMaxVectorByRows(int **matrix, int N) {
	int *vector = new int[N];
	for (int i = 0; i < N; i++) {
		int max = INT_MIN;
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] > max) {
				max = matrix[i][j];
			}
		}
		vector[i] = max;
	}
	return vector;
}

int* getMinVectorByCols(int **matrix, int N) {
	int *vector = new int[N];
	for (int i = 0; i < N; i++) {
		int min = INT_MAX;
		for (int j = 0; j < N; j++) {
			if (matrix[j][i] < min) {
				min = matrix[j][i];
			}
		}
		vector[i] = min;
	}
	return vector;
}

double average(int *vector, int N) {
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += vector[i] * 1.0; //умножаю на 1.0 для преобразования в double
	}
	return sum / N;
}

int* getVectorMaxMinusMin(int **matrix, int N) {
	int *vector = new int[N];
	for (int i = 0; i < N; i++) {
		int min = INT_MAX, max = INT_MIN;
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] < min) {
				min = matrix[i][j];
			}
			if (matrix[i][j] > max) {
				max = matrix[i][j];
			}
		}
		vector[i] = max - min;
	}
	return vector;
}

int getNumberOfRowWithMinValue(int *vector, int N) {
	int rowNumber = 0;
	int min = INT_MAX;
	for (int i = 0; i < N; i++) {
		if (vector[i] < min) {
			min = vector[i];
			rowNumber = i;
		}
	}
	return rowNumber;
}

int getNumberOfColWithMinValue(int *vector, int N) {
	int colNumber = 0;
	int min = INT_MAX;
	for (int i = 0; i < N; i++) {
		if (vector[i] < min) {
			min = vector[i];
			colNumber = i;
		}
	}
	return colNumber;
}

int getNumberOfRowWithMaxValue(int *vector, int N) {
	int rowNumber = 0;
	int max = INT_MIN;
	for (int i = 0; i < N; i++) {
		if (vector[i] > max) {
			max = vector[i];
			rowNumber = i;
		}
	}
	return rowNumber;
}

void changeRowsMinMax(int **matrix, int N) {
	int rowMin = getNumberOfRowWithMinValue(getMinVectorByRows(matrix, N), N);
	int rowMax = getNumberOfRowWithMaxValue(getMaxVectorByRows(matrix, N), N);
	int *tempRow = new int[];
	for (int i = 0; i < N; i++) {
		tempRow[i] = matrix[rowMin][i];
	}
	for (int i = 0; i < N; i++) {
		matrix[rowMin][i] = matrix[rowMax][i];
		matrix[rowMax][i] = tempRow[i];
	}
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
	int *vectorMin = getMinVectorByRows(A, N);
	cout << "Вектор из наименьших значений: ";
	for (int i = 0; i < N; i++) {
		cout << vectorMin[i] << " ";
	}
	cout << "\nСреднее арифметическое элементов вектора = " << average(vectorMin, N);
	delete[] vectorMin;

	//27
	int *vectorMaxMinusMin = getVectorMaxMinusMin(A, N);
	cout << "\nВектор из разностей наибольших и наименьших значений элементов строк: ";
	for (int i = 0; i < N; i++) {
		cout << vectorMaxMinusMin[i] << " ";
	}
	delete[] vectorMaxMinusMin;

	//28
	int *vectorMinByRows = getMinVectorByRows(A, N);
	int rowNumber = getNumberOfRowWithMinValue(vectorMinByRows, N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[rowNumber][i];
	}
	cout << "\nСумма элементов строки, в которой расположен наименьший элемент = " << sum;
	delete[] vectorMinByRows;

	//29
	int *vectorMinByCols = getMinVectorByCols(A, N);
	int colNumber = getNumberOfColWithMinValue(vectorMinByCols, N);
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

	return 0;
}

