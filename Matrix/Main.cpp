#include <iostream>
#include <vector>
#include "Matrix.h"

int main() {
	
	Matrix A = Matrix({ 1.0f,2.0f,3.0f,4.0f }, 2, 2);
	Matrix B = Matrix({ 2.0f,3.0f,4.0f,5.0f }, 2, 2);

	A.print();
	B.print();
	Matrix C = A * B;
	C.print();
	std::cout << C.max();
	
}