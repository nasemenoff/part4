#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Matrix.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	Matrix matrix(3, 3);
	cout << "Матрица 1\n" << matrix;
	Matrix matrixCopy(matrix);
	cout << "\nКопия матрицы\n" << matrixCopy;
	Matrix matrix2(5, 4);
	cout << "\nМатрица 2\n" << matrix2;
	cout << "\nСумма матриц\n";
	cout << matrix + matrix2;
	cout << "\nДоступ к элементу по индексу\n" << matrix[2][2];
	Matrix vMin = matrix.getMinVectorByRows();
	cout << "\nВекторы наименьших и наибольших значений\n" << vMin << matrix.getMaxVectorByRows() << matrix.getMinVectorByCols();
	cout << "\nСреднее арифметическое элементов вектора\n" << vMin.average() << endl;
	matrix = matrix2;
	cout << endl << matrix << endl;
	system("pause");
}
