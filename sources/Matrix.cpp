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
        if (this->row != mat.row || this->col != mat.col) {
            throw std::invalid_argument("matrices have different size");
        }
        vector<double> addition;
        addition.resize((unsigned int) (mat.row * mat.col));
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
        if (this->row != mat.row || this->col != mat.col) {
            throw std::invalid_argument("matrices have different size");
        }
        for (int i = 0; i < this->my_matrix.size(); i++) {
            this->my_matrix[(unsigned int) i] = this->my_matrix[(unsigned int) i] + mat.my_matrix[(unsigned int) i];
        }
        return *this;
    }

    Matrix Matrix::operator-(const Matrix &mat) {
        if (this->row != mat.row || this->col != mat.col) {
            throw std::invalid_argument("matrices have different size");
        }
        vector<double> subtraction;
        subtraction.resize((unsigned int) (mat.row * mat.col));
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
        if (this->row != mat.row || this->col != mat.col) {
            throw std::invalid_argument("matrices have different size");
        }
        for (int i = 0; i < this->my_matrix.size(); i++) {
            this->my_matrix[(unsigned int) i] = this->my_matrix[(unsigned int) i] - mat.my_matrix[(unsigned int) i];
        }
        return *this;
    }

    double Matrix::mul_vectors(const Matrix &mat, const int r, const int c) {
        double sum = 0.0;
        for (int i = 0; i < this->col; i++) {
            sum += this->my_matrix[(unsigned int) (this->col * r + i)] *
                   mat.my_matrix[(unsigned int) (mat.col * i + c)];
        }
        return sum;

    }

    Matrix Matrix::operator*(const Matrix &mat) {
        if (this->col != mat.row) {
            throw std::invalid_argument("matrices have different size for mul");
        }
        vector<double> mul;
        mul.resize((unsigned int) (this->row * mat.col));
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < mat.col; j++) {
                mul[(unsigned int) (i * mat.col + j)] = mul_vectors(mat, i, j);
            }
        }
        Matrix new_mat(mul, this->row, mat.col);
        return new_mat;
    }

    Matrix &Matrix::operator*=(const Matrix &mat) {
        if (this->col != mat.row) {
            throw std::invalid_argument("matrices have different size for mul");
        }
        vector<double> mul;
        mul.resize((unsigned int) (this->row * mat.col));
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < mat.col; j++) {
                mul[(unsigned int) (i * mat.col + j)] = mul_vectors(mat, i, j);
            }
        }
        this->my_matrix = mul;
        this->col = mat.col;
        return *this;
    }

    Matrix Matrix::operator*(const double scalar) {
        vector<double> mul;
        mul.resize((unsigned int) (this->row * this->col));
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
        if (this->row != mat.row || this->col != mat.col) {
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
        if (this->row != mat.row || this->col != mat.col) {
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
        if (this->row != mat.row || this->col != mat.col) {
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
        if (this->row != mat.row || this->col != mat.col) {
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
        for (int i = 0; i < m.row; i++) {
            output << '[';
            for (int j = 0; j < m.col; j++) {
                output << (m.my_matrix[(unsigned int) (i * m.row + j)]);
                if (j != m.col - 1) {
                    output << " ";
                }

            }
            if (i != m.row) {
                output << "]";
            }
            if (i != m.row - 1) {
                output << "\n";
            }

        }
        return output;
    }

    const int MIN = 48;
    const int MAX = 57;

    std::istream &operator>>(std::istream &input, Matrix &m) {
        int row = 0;
        int col = 0;
        string curr;
        while (!input.eof()) {
            string small_data;
            input >> small_data;
            if (small_data[0] == '[') {
                if (small_data[1] < MIN || small_data[1] > MAX) {
                    throw std::invalid_argument("Invalid Matrix enteredA\n");
                }
            } else if (small_data[1] == ']') {
                if (small_data[2] == 0) {}
                else {
                    if (small_data[2] != ',') {
                        throw std::invalid_argument("Invalid Matrix entered\n");
                    }
                    if (small_data[3] != 0) {
                        throw std::invalid_argument("Invalid Matrix entered\n");
                    }
                }
            }
            curr += small_data;
        }
        for (unsigned int i = 0; i < curr.length(); ++i) {
            if (curr[i] != '[') {
                throw std::invalid_argument("Invalid Matrix entered\n");
            }
            row++;
            i++;
            while (curr[i] != ']') {
                if (curr[i] < MIN || curr[i] > MAX) {
                    throw std::invalid_argument("Invalid Matrix entered\n");
                }
                string value;
                value += curr[i];
                m.my_matrix.push_back(std::stod(value));
                i++;
            }
            i++;
            if (curr[i] == '\0') {
                break;
            }
            if (curr[i] != ',') {
                throw std::invalid_argument("Invalid Matrix entered\n");
            }
        }
        m.row = row;
        if (row == 0) {
            throw std::invalid_argument("Invalid Matrix entered\n");
        }
        m.col = (int) (m.my_matrix.size()) / row;
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
        vector<double> minus;
        minus.resize((unsigned int) (mat.row * mat.col));
        for (int i = 0; i < mat.my_matrix.size(); i++) {
            if (mat.my_matrix[(unsigned int) i] != 0) {
                minus[(unsigned int) i] = mat.my_matrix[(unsigned int) i] * -1;
            } else {
                minus[(unsigned int) i] = 0;
            }
        }
        Matrix new_mat(minus, mat.row, mat.col);
        return new_mat;
    }

    Matrix operator+(Matrix &mat) {
        return mat;
    }

    Matrix operator*(const double scalar, Matrix &mat) {
        vector<double> mul;
        mul.resize((unsigned int) (mat.row * mat.col));
        for (int i = 0; i < mat.my_matrix.size(); i++) {
            mul[(unsigned int) i] = mat.my_matrix[(unsigned int) i] * scalar;
        }
        Matrix new_mat(mul, mat.row, mat.col);
        return new_mat;
    }


}