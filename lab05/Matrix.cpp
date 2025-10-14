//
// Created by Lehel on 2025-10-14.
//

#include "Matrix.h"

#include <bits/random.h>


Matrix::Matrix(int rows, int cols) {
    this->mRows = rows;
    this->mCols = cols;
    this->mElements.reserve(rows*cols);
}

Matrix::Matrix(const Matrix &other) {
    this->mRows = other.mRows;
    this->mCols = other.mCols;
    std::copy(other.mElements.begin(),other.mElements.end(),this->mElements);
}

Matrix::Matrix(Matrix &&other) noexcept {
    this->mRows = other.mRows;
    this->mCols = other.mCols;
    this->mElements = std::move(other.mElements);
    other.mRows = 0;
    other.mCols = 0;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0;i<this->mRows*this->mCols;i++) {
        this->mElements.emplace_back(value);
    }
}

double &Matrix::operator()(int row, int col) {
    if (row >= mRows || col >= mCols) {
        throw std::out_of_range("oops4");
    }
    return this->mElements[row*mRows+col];
}

const double &Matrix::operator()(int row, int col) const {
    if (row >= mRows || col >= mCols) {
        throw std::out_of_range("oops5");
    }
    return this->mElements[row*mRows+col];
}

double *Matrix::operator[](int row) {
    if (row > mRows) {
        throw std::out_of_range("oops2");
    }
    return &mElements[row*mCols];
}

const double *Matrix::operator[](int row) const {
    if (row >= mRows ) {
        throw std::out_of_range("oops3");
    }
    return &mElements[row*mCols];
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this != &other) {
        this->mRows = other.getRows();
        this->mCols = other.getCols();
        std::copy(other.mElements.begin(),other.mElements.end(),this->mElements);
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) noexcept {
    if (this != &other) {
        this->mRows = other.getRows();
        this->mCols = other.getCols();
        this->mElements = std::move(other.mElements);
    }
    return *this;
}

void Matrix::printMatrix(std::ostream &os) const {
    if (this->mElements.empty()) {
        throw throw std::out_of_range("oops");
    }
    for (int i=0;i<this->mRows;i++) {
        for (int j=0;j<this->mCols;j++) {
            os<<this->mElements[i*mRows+j]<<" ";
        }
        os<<"\n";
    }
}

void Matrix::randomMatrix(int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd);
    std::uniform_int_distribution<> dist(a,b);
    for (int i=0;i<this->mRows*this->mCols;i++) {
        this->mElements.emplace_back(dist(gen));
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    mat.printMatrix(os);
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& mat) {
    double val;
    for (int i = 0;i<mat.mRows*mat.mCols;i++) {
        is>> val;
        mat.mElements.emplace_back(val);
    }
    return is;
}

Matrix operator*(const Matrix& x, const Matrix& y) {
    if (x.getRows() == y.getRows() && x.getCols()==y.getCols()) {
        auto *z = new Matrix(x.getRows(),x.getCols());
        for (int i=0;i< z->getRows()*z->getCols();i++) {
            z->mElements.emplace_back(x.mElements[i]*y.mElements[i]);
        }
        return *z;
    }
    throw std::out_of_range("to big");
}

Matrix operator+(const Matrix& x, const Matrix& y) {
    if (x.getRows() == y.getRows() && x.getCols()==y.getCols()) {
        auto *z = new Matrix(x.getRows(),x.getCols());
        for (int i=0;i< z->getRows()*z->getCols();i++) {
            z->mElements.emplace_back(x.mElements[i]+y.mElements[i]);
        }
        return *z;
    }
    throw std::out_of_range("to big");
}






