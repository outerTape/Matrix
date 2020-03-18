#include <iostream>
#include "Matrix.h"

int main() {
	
	Matrix A = Matrix(10, 10);
	Matrix B = Matrix(10, 10);

	A.fill(1.3f);
	B.fill(3.2f);
	(A+B).print();
}