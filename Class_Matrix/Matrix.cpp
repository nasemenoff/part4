#include "Matrix.h"

Matrix::Matrix(int m, int n)
{
	M = m > 0 ? m : 1;
	N = n > 0 ? n : 1;
	matrix = new int* [M];
	for (int i = 0; i < M; i++) {
		matrix[i] = new int[N];
	}
	fillRandom();
}

Matrix::Matrix(const Matrix& copy) { //конструктор копирования
	M = copy.M;
	N = copy.N;
	matrix = new int*[M];
	for (int i = 0; i < M; i++) {
		matrix[i] = new int[N];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = copy.matrix[i][j];
		}
	}
}

void Matrix::fillRandom() {
	srand(time(NULL));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = rand() % 100 + 1;
		}
	}
}

double Matrix::average() {
	double sum = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			sum += matrix[i][j] * 1.0; //умножаю на 1.0 для преобразования в double
		}
	}
	return sum / (M * N);
}

Matrix::~Matrix()
{
	/*for (int i = 0; i < N; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;*/
}

int* Matrix::operator[](const int i) {
	return matrix[i];
}

const Matrix& Matrix::operator=(const Matrix& m) {
	delete[] matrix;
	matrix = new int*[m.M];
	for (int i = 0; i < m.M; i++) {
		matrix[i] = new int[m.N];
	}
	for (int i = 0; i < m.M; i++) {
		for (int j = 0; j < m.N; j++) {
			matrix[i][j] = m.matrix[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& m) {
	if (M == m.M && N == m.N) {
		Matrix res(M, N);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				res.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
			}
		}
		return res;
	}
	else {
		cout << "Матрицы разного размера\n";
	}
}

Matrix Matrix::operator-(const Matrix& m) {
	if (M == m.M && N == m.N) {
		Matrix res(M, N);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				res.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
			}
		}
		return res;
	}
	else {
		cout << "Матрицы разного размера\n";
	}
}

ostream& operator<<(ostream& s, const Matrix& m) {
	for (int i = 0; i < m.M; i++) {
		for (int j = 0; j < m.N; j++) {
			s << m.matrix[i][j] << " ";
		}
		s << endl;
	}
	return s;
}

Matrix Matrix::getMinVectorByRows() {
	Matrix res(1, M);
	for (int i = 0; i < M; i++) {
		int min = INT_MAX;
		for (int j = 0; j < N; j++) {
			int m = matrix[i][j];
			if (m < min) {
				min = m;
			}
		}
		res[0][i] = min;
	}
	return res;
}

Matrix Matrix::getMaxVectorByRows() {
	Matrix res(1, M);
	for (int i = 0; i < M; i++) {
		int max = INT_MIN;
		for (int j = 0; j < N; j++) {
			int m = matrix[i][j];
			if (m > max) {
				max = m;
			}
		}
		res[0][i] = max;
	}
	return res;
}

Matrix Matrix::getMinVectorByCols() {
	Matrix res(1, N);
	for (int i = 0; i < N; i++) {
		int min = INT_MAX;
		for (int j = 0; j < M; j++) {
			int m = matrix[j][i];
			if (m < min) {
				min = m;
			}
		}
		res[0][i] = min;
	}
	return res;
}