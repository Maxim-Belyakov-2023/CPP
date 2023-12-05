#include "Matrix.h"

#include <iomanip>
#include <ostream>

Matrix::Matrix(int size) : size(size)
{
    this->matr = new double*[size];
    for (int i = 0; i < size; ++i)
    {
        this->matr[i] = new double[size];
        for (int j = 0; j < size; ++j)
        {
            this->matr[i][j] = 0;
        }
    }
}

Matrix::Matrix(double** matrix, int size) : size(size)
{
    // TODO
}

Matrix* Matrix::operator+( Matrix* matrix)
{
    // TODO: Если размер матриц не совпадает, генерировать исключение
    Matrix* tmp = new Matrix(this->size);
    for (int i = 0; i < this->size; ++i)
        for (int j = 0; j < this->size; ++j)
            tmp->matr[i][j] = this->matr[i][j] + matrix->matr[i][j];
    return tmp;
}

Matrix Matrix::operator+(double number)
{
    Matrix* tmp = new Matrix(this->size);
    for (int i = 0; i < this->size; ++i)
    {
        for (int j = 0; j < this->size; j++)
        {
            tmp->matr[i][j] += number;
        }
    }
    return *tmp;
}

Matrix Matrix::operator*(const Matrix* matrix)
{
    Matrix* tmp = new Matrix(this->size);
    for (int i = 0; i < this->size; ++i)
    {
        for (int j = 0; j < this->size; ++j)
        {
            for ( int k = 0; k< this->size;++k)
            {
                tmp->matr[i][j]+=this->matr[i][k]*matrix->matr[j][k];
            }
        }
    }
    return *tmp;
}


std::ostream& operator<<(std::ostream& stream, const Matrix* matrix)
{
    for (int i = 0; i < matrix->size; ++i)
    {
        for (int j = 0; j < matrix->size; ++j)
        {
            stream << std::left << std::setw(4) << std::setprecision(2) << matrix->matr[i][j];
        }
        stream << std::endl;
    }
    return stream;
}

std::istream& operator>>(std::istream& stream, const Matrix* matrix)
{
    for (int i = 0; i < matrix->size; ++i)
    {
        for (int j = 0; j < matrix->size; ++j)
        {
            stream >> matrix->matr[i][j];
        }
    }
    return stream;
}

void Matrix::RandomGenerate()
{
    srand(time(0));
    for(int i = 0; i < size; i++ )
    {
        for (int j = 0; j < size; j++)
        {
            this->matr[i][j] = (double)rand() / RAND_MAX * 100;
        }
    }
}


// / * - + > < >= <= == != ++ -- [] () :: . % & | << >> ~ ^ += -= *= /= %= |= &= <<= >>= ^= ~= -> new delete !
