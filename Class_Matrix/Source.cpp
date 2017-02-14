#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Matrix.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	Matrix matrix(3, 3);
	cout << "������� 1\n" << matrix;
	Matrix matrixCopy(matrix);
	cout << "\n����� �������\n" << matrixCopy;
	Matrix matrix2(5, 4);
	cout << "\n������� 2\n" << matrix2;
	cout << "\n����� ������\n";
	cout << matrix + matrix2;
	cout << "\n������ � �������� �� �������\n" << matrix[2][2];
	Matrix vMin = matrix.getMinVectorByRows();
	cout << "\n������� ���������� � ���������� ��������\n" << vMin << matrix.getMaxVectorByRows() << matrix.getMinVectorByCols();
	cout << "\n������� �������������� ��������� �������\n" << vMin.average() << endl;
	matrix = matrix2;
	cout << endl << matrix << endl;
	system("pause");
}
