#include <iostream>
#include <vector>
#include "Matrix.h"

int main() {
	
	/*Matrix A = Matrix(2, 2);
	Matrix B = Matrix(2, 2);

	A.fill(2.0f);
	B.fill(3.0f);
	(A*B).print();*/
	
	std::vector<float> x{ 1.0f,2.0f };
	std::vector<float> y;
	y = x;
	for (int i = 0; i < x.size(); i++) {
		std::cout << x[i];
	}
	std::cout << std::endl;
}