#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Matrix
{
private:
	int **matrix;
	int M = 0, N = 0;
public:
	Matrix(int m = 1, int n = 1);
	Matrix(const Matrix& copy);
	void fillRandom();
	double average();
	friend ostream& operator<<(ostream& os, const Matrix& m);
	int* operator[](int M);
	const Matrix& operator=(const Matrix& m);
	Matrix operator+(const Matrix& m);
	Matrix operator-(const Matrix& m);
	Matrix getMinVectorByRows();
	Matrix getMaxVectorByRows();
	Matrix getMinVectorByCols();
	~Matrix();
};

