#pragma once
#include <ostream>

class Matrix
{
private:
    double **matr;
    int size;
public:
    Matrix(int size);
    Matrix(double** matrix, int size);

    Matrix operator+(const Matrix* matrix);

    friend std::ostream& operator<<(std::ostream& stream, const Matrix* matrix);
    friend std::istream& operator>>(std::istream& stream, const Matrix* matrix);
};
