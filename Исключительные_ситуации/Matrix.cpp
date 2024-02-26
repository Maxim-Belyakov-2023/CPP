#include "Matrix.h"

#include "incorrect_dimension_error.h"
#include "out_of_range_error.h"

Matrix::MatrixRow::MatrixRow() = default;

Matrix::MatrixRow::MatrixRow(int size) : col(size)
{
    this->values = new double[size];
}

double& Matrix::MatrixRow::operator[](int n)
{
    if (n < col && n >= 0)
        return this->values[n];
    throw out_of_range_error("Выход за границы строки");
}

Matrix::MatrixRow& Matrix::operator[](int n)
{
    if (n < col && n >= 0)
        return this->matr[n];
    else
    {
        throw out_of_range_error("Выход за границы строки");
    }
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
    if(this->row!= matrix.row || this->col != matrix.col)
    {
        throw incorrect_dimension_error("Не совпадают размерности матриц");
    }
    else
    {
        for (int i = 0; i < this->row; ++i)
            for (int j = 0; j < this->col; ++j)
                tmp->matr[i][j] = this->matr[i][j] + matrix.matr[i][j];
        return *tmp;
    }
    
    
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
    double det = 1.0;
    for (int i = 0; i < this->col; i++)
    {
        int pivot = i;
        for (int j = i + 1; j < this->row; j++)
        {
            if (abs(matr[j][i]) > abs(matr[pivot][i]))
            {
                pivot = j;
            }
        }
        if (pivot != i)
        {
            std::swap(matr[i], matr[pivot]);
            det *= -1;
        }
        if (matr[i][i] == 0)
        {
            return 0;
        }
        det *= matr[i][i];
        for (int j = i + 1; j < this->row; j++)
        {
            double factor = matr[j][i] / matr[i][i];
            for (int k = i + 1; k < this->col; k++)
            {
                matr[j][k] -= factor * matr[i][k];
            }
        }
    }
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
Matrix::~Matrix()
{
    delete[] this->matr;
}
