#include "Matrix.h"

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

Matrix Matrix::operator+(Matrix matrix) const
{
    // TODO: Если размер матриц не совпадает, генерировать исключение
    Matrix* tmp = new Matrix(this->size);
    for (int i = 0; i < this->size; ++i)
        for (int j = 0; j < this->size; ++j)
            tmp->matr[i][j] = this->matr[i][j] + matrix.matr[i][j];
    return *tmp;
}

Matrix Matrix::operator+(double number) const
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

Matrix Matrix::operator*(const Matrix* matrix) const
{
    Matrix* tmp = new Matrix(this->size);
    for (int i = 0; i < this->size; ++i)
        for (int j = 0; j < this->size; ++j)
            for (int k = 0; k < this->size; ++k)
                tmp->matr[i][j] += this->matr[i][k] * matrix->matr[j][k];
    return *tmp;
}

Matrix& Matrix::operator++()
{
    for (int i = 0; i < this->size; ++i)
    {
        for (int j = 0; j < this->size; j++)
        {
            this->matr[i][j]++;
        }
    }

    return *this;
}

Matrix& Matrix::operator++(int) const
{
    Matrix tmp = *this;
    for (int i = 0; i < this->size; ++i)
    {
        for (int j = 0; j < this->size; j++)
        {
            this->matr[i][j]++;
        }
    }
    return tmp;
}

bool Matrix::operator==(const Matrix& matrix) const
{
    if (this->size != matrix.size)
        return false;
    for (int i = 0; i < this->size; ++i)
    {
        for (int j = 0; j < this->size; j++)
        {
            if (matrix.matr[i][j] != matr[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& matrix) const
{
    return !(*this == matrix);
}

Matrix::operator double()
{
    int** matrix = new int*[this->size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int** matrix = new int*[size];
            matrix[i][j] = matr[i][j];
        }
    }
    double det = 1.0;
    for (int i = 0; i < size; i++)
    {
        int pivot = i;
        for (int j = i + 1; j < size; j++)
        {
            if (abs(matrix[j][i]) > abs(matrix[pivot][i]))
            {
                pivot = j;
            }
        }
        if (pivot != i)
        {
            std::swap(matrix[i], matrix[pivot]);
            det *= -1;
        }
        if (matrix[i][i] == 0)
        {
            return 0;
        }
        det *= matrix[i][i];
        for (int j = i + 1; j < size; j++)
        {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i + 1; k < size; k++)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    for (int i = 0; i < size; ++i)
        delete[] matrix[i];
    delete[] matrix;
    return det;
}

std::ostream& operator<<(std::ostream& stream, const Matrix* matrix)
{
    for (int i = 0; i < matrix->size; ++i)
    {
        for (int j = 0; j < matrix->size; ++j)
        {
            stream << std::left << std::setw(10) << std::fixed << std::setprecision(2) << matrix->matr[i][j];
        }
        stream << '\n';
    }
    return stream;
}

std::ostream& operator<<(std::ostream& stream, Matrix matrix)
{
    return operator<<(stream, &matrix);
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

void Matrix::RandomGenerate() const
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            this->matr[i][j] = static_cast<double>(rand()) / RAND_MAX * 100;
        }
    }
}
