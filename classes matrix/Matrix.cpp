#include "Matrix.h"

template <typename T>
Matrix<T>::Matrix() {
	this->rows = 0;
	this->columns = 0;
	arr = nullptr;
}

template <typename T>
Matrix<T>::Matrix(int r, int c) {
	this->rows = r;
	this->columns = c;
	arr = new T * [r];
	for (int i = 0; i < r; i++) {
		arr[i] = new T[c];
	}
}

template <typename T>
Matrix<T>::Matrix(int r, int c, T** a) {
	this->rows = r;
	this->columns = c;
	arr = new T * [r];
	for (int i = 0; i < r; i++) {
		arr[i] = new T[c];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] = a[i][j];
		}
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix& m) {
	this->rows = m.rows;
	this->columns = m.columns;
	arr = new T * [rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new T[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			arr[i][j] = m.arr[i][j];
		}
	}
}

template <typename T>
Matrix<T>::~Matrix() {
	if (arr != nullptr) {
		for (int i = 0; i < rows; i++) {
			if (arr[i] != nullptr) {
				delete[] arr[i];
			}
		}
		delete[] arr;
	}
}

template <typename T>
void Matrix<T>::info()const {
	cout << "-------------------------------------------\n";
	cout << "Rows : " << rows << endl;
	cout << "Columns : " << columns << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-------------------------------------------\n\n";
}

template <typename T>
void Matrix<T>::setParameters(int rows, int columns, T** arr) {
	if (this->arr != nullptr) {
		for (int i = 0; i < this->rows; i++) {
			if (this->arr[i] != nullptr) {
				delete[] this->arr[i];
			}
		}
		delete[] this->arr;
	}
	this->rows = rows;
	this->columns = columns;
	this->arr = new T * [rows];
	for (int i = 0; i < rows; i++) {
		this->arr[i] = new T[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			this->arr[i][j] = arr[i][j];
		}
	}
}

template <typename T>
void Matrix<T>::setAt(int rowIndex, int columnIndex, T value) {
	arr[rowIndex][columnIndex] = value;
}

template <typename T>
T* Matrix<T>::operator[](int rowIndex) {
	return arr[rowIndex];
}

template <typename T>
void Matrix<T>::removeAll() {
	if (arr != nullptr) {
		for (int i = 0; i < rows; i++) {
			if (arr[i] != nullptr) {
				delete[] arr[i];
			}
		}
		delete[] arr;
		arr = nullptr;
	}
}

template <typename T>
void Matrix<T>::enterValues() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "Enter value for element with index [" << i << "][" << j << "] : "; cin >> arr[i][j];
		}
	}
}

template <typename T>
void Matrix<T>::fillWithRandomValues() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			arr[i][j] = rand() % 31;
		}
	}
}

template <typename T>
T Matrix<T>::findMax() {
	T max = arr[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			max = arr[i][j] > max ? arr[i][j] : max;
		}
	}
	return max;
}

template <typename T>
T Matrix<T>::findMin() {
	T min = arr[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			min = arr[i][j] < min ? arr[i][j] : min;
		}
	}
	return min;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(T value) {
	Matrix<T> newArr(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newArr.arr[i][j] = arr[i][j] + value;
		}
	}
	return newArr;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(T value) {
	Matrix<T> newArr(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newArr.arr[i][j] = arr[i][j] - value;
		}
	}
	return newArr;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(T value) {
	Matrix<T> newArr(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newArr.arr[i][j] = arr[i][j] * value;
		}
	}
	return newArr;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(T value) {
	Matrix<T> newArr(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newArr.arr[i][j] = arr[i][j] / value;
		}
	}
	return newArr;
}

template <typename T>
void Matrix<T>::operator=(Matrix matrix) {
	if (arr != nullptr) {
		for (int i = 0; i < rows; i++) {
			if (arr[i] != nullptr) {
				delete[] arr[i];
			}
		}
		delete[] arr;
	}
	this->rows = matrix.rows;
	this->columns = matrix.columns;
	arr = new T * [rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new T[columns];
		for (int j = 0; j < columns; j++) {
			arr[i][j] = matrix.arr[i][j];
		}
	}
}