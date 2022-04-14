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
            addition[i] = this->my_matrix[i] + mat.my_matrix[i];
        }
        new_mat = Matrix::Matrix(addition, this->row, this->col);
        return new_mat;
    }

    Matrix &Matrix::operator++() {
        for (int i = 0; i < this->my_matrix.size(); i++) {
            this->my_matrix[i] += 1;
        }
        return *this;
    }

    Matrix Matrix::operator++(const int num) {
        Matrix copy = *this;
        for (int i = 0; i < this->my_matrix.size(); i++) {
            this->my_matrix[i] += 1;
        }
        return copy;
    }

    Matrix &Matrix::operator+=(const Matrix &mat) {
        if (this->row != mat.row || this->col != this->col) {
            throw std::invalid_argument("matrices have different size");
        }
        for (int i = 0; i < this->my_matrix.size(); i++) {
            this->my_matrix[i] = this->my_matrix[i] + mat.my_matrix[i];
        }
        return *this;
    }

    Matrix Matrix::operator-(const Matrix &mat) {
        if (this->row != mat.row || this->col != this->col) {
            throw std::invalid_argument("matrices have different size");
        }
        vector<double> subtraction;
        for (int i = 0; i < this->my_matrix.size(); i++) {
            addition[i] = this->my_matrix[i] - mat.my_matrix[i];
        }
        new_mat = Matrix::Matrix(subtraction, this->row, this->col);
        return new_mat;
    }
}

Matrix &Matrix::operator--() {
    for (int i = 0; i < this->my_matrix.size(); i++) {
        this->my_matrix[i] -= 1;
    }
    return *this;
}

Matrix Matrix::operator--(const int num) {
    Matrix copy = *this;
    for (int i = 0; i < this->my_matrix.size(); i++) {
        this->my_matrix[i] -= 1;
    }
    return copy;
}

Matrix &Matrix::operator-=(const Matrix &mat) {
    if (this->row != mat.row || this->col != this->col) {
        throw std::invalid_argument("matrices have different size");
    }
    for (int i = 0; i < this->my_matrix.size(); i++) {
        this->my_matrix[i] = this->my_matrix[i] - mat.my_matrix[i];
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
        mul[i] = this->my_matrix[i] * scalar;
    }
    new_mat = Matrix::Matrix(mul, this->row, this->col);
    return new_mat;
}

Matrix &Matrix::operator*=(const double scalar) {
    for (int i = 0; i < this->my_matrix.size(); i++) {
        this->my_matrix[i] = this->my_matrix[i] * scalar;
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
        sum_this+=this->my_matrix[i];
        sum_other+=mat->my_matrix[i];
    }
    return sum_this>sum_other;
}

bool Matrix::operator>=(Matrix &mat) {
    if (this->row != mat.row || this->col != this->col) {
        throw std::invalid_argument("matrices have different size");
    }
    double sum_this = 0.0;
    double sum_other = 0.0;
    for (int i = 0; i < this->my_matrix.size(); i++) {
        sum_this+=this->my_matrix[i];
        sum_other+=mat->my_matrix[i];
    }
    return sum_this>=sum_other;
}

bool Matrix::operator<(Matrix &mat) {     if (this->row != mat.row || this->col != this->col) {
        throw std::invalid_argument("matrices have different size");
    }
    double sum_this = 0.0;
    double sum_other = 0.0;
    for (int i = 0; i < this->my_matrix.size(); i++) {
        sum_this+=this->my_matrix[i];
        sum_other+=mat->my_matrix[i];
    }
    return sum_this<sum_other; }

bool Matrix::operator<=(Matrix &mat) {     if (this->row != mat.row || this->col != this->col) {
        throw std::invalid_argument("matrices have different size");
    }
    double sum_this = 0.0;
    double sum_other = 0.0;
    for (int i = 0; i < this->my_matrix.size(); i++) {
        sum_this+=this->my_matrix[i];
        sum_other+=mat->my_matrix[i];
    }
    return sum_this<=sum_other; }


std::ostream &operator<<(std::ostream &output, const Matrix &m) {
    return output;
}

std::istream &operator>>(std::istream &input, Matrix &m) {
    return input;
}

bool operator==(const Matrix &m1, const Matrix &m2) {     if (this->row != mat.row || this->col != this->col) {
        throw std::invalid_argument("matrices have different size");
    }
    double sum_this = 0.0;
    double sum_other = 0.0;
    for (int i = 0; i < this->my_matrix.size(); i++) {
        sum_this+=this->my_matrix[i];
        sum_other+=mat->my_matrix[i];
    }
    return sum_this==sum_other; }

bool operator!=(const Matrix &m1, const Matrix &m2) {
    if (this->row != mat.row || this->col != this->col) {
        throw std::invalid_argument("matrices have different size");
    }
    double sum_this = 0.0;
    double sum_other = 0.0;
    for (int i = 0; i < this->my_matrix.size(); i++) {
        sum_this+=this->my_matrix[i];
        sum_other+=mat->my_matrix[i];
    }
    return sum_this!=sum_other;
}

Matrix operator-(Matrix &mat) {

}

Matrix operator+(Matrix &mat) {

}

Matrix operator*(const double scalar, Matrix &mat) {

}


}