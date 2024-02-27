#include "Matrix.h"

#include <iostream>

Matrix::MatrixRow::MatrixRow() = default;

Matrix::MatrixRow::MatrixRow(int size) : col(size)
{
    this->values = new double[size];
}

double& Matrix::MatrixRow::operator[](int n)
{
    if (n < col && n >= 0)
        return this->values[n];
    else
    {
        std::cout << "Выход за границы Row";
    }
}

Matrix::MatrixRow& Matrix::operator[](int n)
{
    if (n < col && n >= 0)
        return this->matr[n];
    else
    {
        std::cout << "Выход за границы";
    }
}

Matrix& Matrix::operator=(const Matrix& matrix)
{
    this->col = matrix.col;
    this->row = matrix.row;
    this->matr = matrix.matr;
    return *this;
}

Matrix::Matrix(int row, int col) : col(col), row(row)
{
    this->matr = new MatrixRow[row];
    for (int i = 0; i < row; ++i)
        this->matr[i] = MatrixRow(col);
}

Matrix::Matrix(double** matrix, int col, int row)
{
    // TODO
}

Matrix Matrix::operator+(Matrix matrix) const
{
    // TODO: Если размер матриц не совпадает, генерировать исключение
    Matrix* tmp = new Matrix(row, col);
    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->col; ++j)
            tmp->matr[i][j] = this->matr[i][j] + matrix.matr[i][j];
    return *tmp;
}

Matrix Matrix::operator+(double number) const
{
    Matrix* tmp = new Matrix(row, col);
    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->col; j++)
        {
            tmp->matr[i][j] += number;
        }
    }
    return *tmp;
}

Matrix Matrix::operator*(const Matrix* matrix) const
{
    Matrix* tmp = new Matrix(row, matrix->col);
    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < matrix->col; ++j)
            for (int k = 0; k < matrix->row; ++k)
                tmp->matr[i][j] += this->matr[i][k] * matrix->matr[j][k];
    return *tmp;
}

Matrix& Matrix::operator++()
{
    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->matr[i][j]++;
        }
    }

    return *this;
}

Matrix& Matrix::operator++(int) const
{
    Matrix tmp = *this;
    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->matr[i][j]++;
        }
    }
    return tmp;
}

bool Matrix::operator==(const Matrix& matrix) const
{
    if (this->col != matrix.col && this->row != matrix.row)
        return false;
    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->col; j++)
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
    int** matrix= new int* [this->row];
    for(int i = 0; i< this->row;i++)
    {
        for(int j = 0; j< this->col;j++)
        {
            int** matrix= new int* [this->col];
            matrix[i][j]=matr[i][j];
        }
    }
    double det = 1.0;
    for (int i = 0; i < this->row; i++) {
        int pivot = i;
        for (int j = i + 1; j < this->col; j++) {
            if (abs(matrix[j][i]) > abs(matrix[pivot][i])) {
                pivot = j;
            }
        }
        if (pivot != i) {
            std::swap(matrix[i], matrix[pivot]);
            det *= -1;
        }
        if (matrix[i][i] == 0) {
            return 0;
        }
        det *= matrix[i][i];
        for (int j = i + 1; j < this->row; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i + 1; k < this->col; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    for (int i = 0; i < row; ++i)
        delete[] matrix[i];
    delete[] matrix;
    return det;
}

std::ostream& operator<<(std::ostream& stream, const Matrix* matrix)
{
    for (int i = 0; i < matrix->row; ++i)
    {
        for (int j = 0; j < matrix->col; ++j)
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
    for (int i = 0; i < matrix->row; ++i)
    {
        for (int j = 0; j < matrix->col; ++j)
        {
            stream >> matrix->matr[i][j];
        }
    }
    return stream;
}


Matrix& Matrix::operator,(const Matrix& matrix)
{
    Matrix matrix3(row, col + matrix.col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col + matrix.col; j++)
        {
            if (j < col)
            {
                matrix3[i][j] = this->matr[i][j];
            }
            else
            {
                matrix3[i][j] = matrix.matr[i][j % col];
            }
        }
    }
    return matrix3;
}

void Matrix::RandomGenerate()
{
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->matr[i][j] = static_cast<double>(rand()) / RAND_MAX * 100;
        }
    }
}
