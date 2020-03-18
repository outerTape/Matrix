#include <iostream>
#include <vector>
#include <string>

struct Matrix {
    std::vector<float> matrix_values;
    int n_rows, n_cols;

    Matrix(int a, int b) {
        n_rows = a;
        n_cols = b;
        matrix_values.assign(n_rows * n_cols, 0.0f);
    }

    Matrix(std::vector<float> values, int a, int b) {
        n_rows = a;
        n_cols = b;
        assign(values);
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

    void assign(std::vector<float> values) {
        matrix_values = values;
    }

    float& operator()(int x, int y) {
        return matrix_values[y + n_cols * x];
    }

    Matrix operator+(Matrix& rhs) {
        if ((n_rows != rhs.n_rows) | (n_cols != rhs.n_cols)) {
            std::printf("Matrix dimensions are not equal!");
            exit(-1);
        }
            
        Matrix sum(n_rows, n_cols);
        for (int i = 0; i < n_rows * n_cols; i++) {
            sum.matrix_values[i] = matrix_values[i] + rhs.matrix_values[i];
        }
        return sum;
    }

    Matrix operator-(Matrix& rhs) {
        if ((n_rows != rhs.n_rows) | (n_cols != rhs.n_cols)) {
            std::printf("Matrix dimensions are not equal!");
            exit(-1);
        }

        Matrix diff(n_rows, n_cols);
        for (int i = 0; i < n_rows * n_cols; i++) {
            diff.matrix_values[i] = matrix_values[i] - rhs.matrix_values[i];
        }
        return diff;
    }

    Matrix operator*(Matrix& rhs) {
        if (n_cols != rhs.n_rows) {
            std::printf("Matrix dimensions are compatible!");
            exit(-1);
        }

        Matrix product(n_rows, rhs.n_cols);
        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < rhs.n_cols; j++) {
                for (int k = 0; k < n_cols; k++) {
                    product(i, j) += (*this)(i, k) * rhs(k, j);
                }
            }
            
        }
        return product;
    }
};