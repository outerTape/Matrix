#include <iostream>
#include <vector>

struct Matrix {
    std::vector<float> matrix_values;
    int n_rows, n_cols;

    Matrix(int a, int b) {
        n_rows = a;
        n_cols = b;
        matrix_values.assign(n_rows * n_cols, 0.0f);
    }

    void print() {
        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                std::cout << (*this)(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    void fill(float a) {
        matrix_values.assign(n_rows * n_cols, a);
    }

    float& operator()(int x, int y) {
        return matrix_values[x + n_rows * y];
    }

    Matrix operator+(Matrix& rhs) {
        Matrix sum(n_rows, n_cols);
        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                sum(i, j) = (*this)(i, j) + rhs(i, j);
            }
        }
        return sum;
    }
};