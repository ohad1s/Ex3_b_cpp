#include "Matrix.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

namespace zich {
    Matrix::Matrix(const vector<double> &matrix, const int row, const int col) {
        if (row <= 0 || col <= 0) {
            throw std::invalid_argument("row or col can't be negative or 0");
        }

        if (matrix.size() != row * col) {
            throw std::invalid_argument("matrix size must be equal to row*col");
        }
        this->my_matrix = matrix;
        this->row = row;
        this->col = col;
    }

    Matrix::~Matrix() {}

    Matrix Matrix::operator+(Matrix const &mat) {
        if (this->row != mat.row || this->col != this->col) {
            throw std::invalid_argument("matrices have different size");
        }
        vector<double> addition;
        for (int i = 0; i < this->my_matrix.size(); i++) {
            addition[(unsigned int) i] = this->my_matrix[(unsigned int) i] + mat.my_matrix[(unsigned int) i];
        }
        Matrix new_mat(addition, this->row, this->col);
        return new_mat;
    }

    Matrix &Matrix::operator++() {
        for (int i = 0; i < this->my_matrix.size(); i++) {
            this->my_matrix[(unsigned int) i] += 1;
        }
        return *this;
    }

    Matrix Matrix::operator++(const int num) {
        Matrix copy = *this;
        for (int i = 0; i < this->my_matrix.size(); i++) {
            this->my_matrix[(unsigned int) i] += 1;
        }
        return copy;
    }

    Matrix &Matrix::operator+=(const Matrix &mat) {
        if (this->row != mat.row || this->col != this->col) {
            throw std::invalid_argument("matrices have different size");
        }
        for (int i = 0; i < this->my_matrix.size(); i++) {
            this->my_matrix[(unsigned int) i] = this->my_matrix[(unsigned int) i] + mat.my_matrix[(unsigned int) i];
        }
        return *this;
    }

    Matrix Matrix::operator-(const Matrix &mat) {
        if (this->row != mat.row || this->col != this->col) {
            throw std::invalid_argument("matrices have different size");
        }
        vector<double> subtraction;
        for (int i = 0; i < this->my_matrix.size(); i++) {
            subtraction[(unsigned int) i] = this->my_matrix[(unsigned int) i] - mat.my_matrix[(unsigned int) i];
        }
        Matrix new_mat(subtraction, this->row, this->col);
        return new_mat;
    }


    Matrix &Matrix::operator--() {
        for (int i = 0; i < this->my_matrix.size(); i++) {
            this->my_matrix[(unsigned int) i] -= 1;
        }
        return *this;
    }

    Matrix Matrix::operator--(const int num) {
        Matrix copy = *this;
        for (int i = 0; i < this->my_matrix.size(); i++) {
            this->my_matrix[(unsigned int) i] -= 1;
        }
        return copy;
    }

    Matrix &Matrix::operator-=(const Matrix &mat) {
        if (this->row != mat.row || this->col != this->col) {
            throw std::invalid_argument("matrices have different size");
        }
        for (int i = 0; i < this->my_matrix.size(); i++) {
            this->my_matrix[(unsigned int) i] = this->my_matrix[(unsigned int) i] - mat.my_matrix[(unsigned int) i];
        }
        return *this;
    }

    Matrix Matrix::operator*(const Matrix &mat) {
    }

    Matrix &Matrix::operator*=(const Matrix &mat) {
        return *this;
    }

    Matrix Matrix::operator*(const double scalar) {
        vector<double> mul;
        for (int i = 0; i < this->my_matrix.size(); i++) {
            mul[(unsigned int) i] = this->my_matrix[(unsigned int) i] * scalar;
        }
        Matrix new_mat(mul, this->row, this->col);
        return new_mat;
    }

    Matrix &Matrix::operator*=(const double scalar) {
        for (int i = 0; i < this->my_matrix.size(); i++) {
            this->my_matrix[(unsigned int) i] = this->my_matrix[(unsigned int) i] * scalar;
        }
        return *this;
    }

    bool Matrix::operator>(Matrix &mat) {
        if (this->row != mat.row || this->col != this->col) {
            throw std::invalid_argument("matrices have different size");
        }
        double sum_this = 0.0;
        double sum_other = 0.0;
        for (int i = 0; i < this->my_matrix.size(); i++) {
            sum_this += this->my_matrix[(unsigned int) i];
            sum_other += mat.my_matrix[(unsigned int) i];
        }
        return sum_this > sum_other;
    }

    bool Matrix::operator>=(Matrix &mat) {
        if (this->row != mat.row || this->col != this->col) {
            throw std::invalid_argument("matrices have different size");
        }
        double sum_this = 0.0;
        double sum_other = 0.0;
        for (int i = 0; i < this->my_matrix.size(); i++) {
            sum_this += this->my_matrix[(unsigned int) i];
            sum_other += mat.my_matrix[(unsigned int) i];
        }
        return sum_this >= sum_other;
    }

    bool Matrix::operator<(Matrix &mat) {
        if (this->row != mat.row || this->col != this->col) {
            throw std::invalid_argument("matrices have different size");
        }
        double sum_this = 0.0;
        double sum_other = 0.0;
        for (int i = 0; i < this->my_matrix.size(); i++) {
            sum_this += this->my_matrix[(unsigned int) i];
            sum_other += mat.my_matrix[(unsigned int) i];
        }
        return sum_this < sum_other;
    }

    bool Matrix::operator<=(Matrix &mat) {
        if (this->row != mat.row || this->col != this->col) {
            throw std::invalid_argument("matrices have different size");
        }
        double sum_this = 0.0;
        double sum_other = 0.0;
        for (int i = 0; i < this->my_matrix.size(); i++) {
            sum_this += this->my_matrix[(unsigned int) i];
            sum_other += mat.my_matrix[(unsigned int) i];
        }
        return sum_this <= sum_other;
    }


    std::ostream &operator<<(std::ostream &output, const Matrix &m) {
        return output;
    }

    std::istream &operator>>(std::istream &input, Matrix &m) {
        return input;
    }

    bool operator==(const Matrix &m1, const Matrix &m2) {
        if (m1.row != m2.row || m1.col != m2.col) {
            throw std::invalid_argument("matrices have different size");
        }
        for (int i = 0; i < m1.my_matrix.size(); i++) {
            int d_this = m1.my_matrix[(unsigned int) i];
            int d_other = m2.my_matrix[(unsigned int) i];
            if (d_this != d_other) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Matrix &m1, const Matrix &m2) {
        return !(m1 == m2);
    }

    Matrix operator-(Matrix &mat) {

    }

    Matrix operator+(Matrix &mat) {

    }

    Matrix operator*(const double scalar, Matrix &mat) {

    }


}