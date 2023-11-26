#include "Matrix.h"

Matrix::Matrix(int size) : size(size)
{
    this->matr = new double*[size];
    for (int i = 0; i < size; ++i)
        this->matr[i] = new double[size];
}

Matrix::Matrix(double** matrix, int size) : size(size)
{
    // TODO
}
