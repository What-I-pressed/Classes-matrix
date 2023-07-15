#include <string>
#include "Matrix.h"
#include "Matrix.cpp"

void main() {
	srand(time(NULL));
	int** arr = new int* [2];
	for (int i = 0; i < 2; i++) {
		arr[i] = new int[2];
	}
	Matrix<int> matrix1(2, 4, arr);
	matrix1.fillWithRandomValues();
	matrix1.info();
	matrix1.enterValues();
	matrix1.info();
	matrix1 = matrix1 + 2;
	cout << "matrix1 + 2 : " << endl;
	matrix1.info();
	matrix1 = matrix1 - 2;
	cout << "matrix1 - 2 : " << endl;
	matrix1.info();
	matrix1 = matrix1 * 2;
	cout << "matrix1 * 2 : " << endl;
	matrix1.info();
	matrix1 = matrix1 / 2;
	cout << "matrix1 / 2 : " << endl;
	matrix1.info();
	cout << "Max : " << matrix1.findMax() << endl;
	cout << "Min : " << matrix1.findMin() << endl;
	matrix1.removeAll();
}