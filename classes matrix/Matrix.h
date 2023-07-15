#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Matrix
{
	int rows, columns;
	T** arr;
public:
	Matrix();

	Matrix(int r, int c);

	Matrix(int r, int c, T** a);

	Matrix(const Matrix& m);

	~Matrix();

	void info()const;

	void setParameters(int rows, int columns, T** arr);

	void setAt(int rowIndex, int columnIndex, T value);

	T* operator[](int rowIndex);

	void removeAll();

	void enterValues();

	void fillWithRandomValues();

	T findMax();

	T findMin();

	Matrix operator+(T value);

	Matrix operator-(T value);

	Matrix operator*(T value);

	Matrix operator/(T value);

	void operator=(Matrix matrix);
};

