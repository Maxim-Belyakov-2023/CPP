#pragma once

class Matrix
{
private:
    double **matr;
    int size;
public:
    Matrix(int size);
    Matrix(double** matrix, int size);
};
