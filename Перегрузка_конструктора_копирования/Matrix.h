#pragma once
#include <iomanip>

class Matrix
{
private:
    int col;
    int row;
    // Вложенный класс
    class MatrixRow
    {
    private:
        double* values;
        int col;
    public:
        MatrixRow();
        MatrixRow(int col);

        double& operator[](int n);
    };

    MatrixRow *matr;
    
public:

    Matrix(int row,int col);
    Matrix(double** matrix, int row,int col);
    // Конструктор копирования
    // По идее, должен создавать копию объекта, не связанную с исходным объектом!!!!!!!
    // Применительно к данному классу, конструктор копирования по умолчанию будет копировать ссылки, а не значения,
    // поэтому необходимо переопределить этот конструкто.
    Matrix(const Matrix& matrix);

    Matrix operator+(Matrix matrix) const;
    Matrix operator+(double number) const;
    Matrix operator*(const Matrix* matrix) const;

    Matrix& operator++();

    Matrix& operator++(int) const;

    bool operator==(const Matrix& matrix) const;
    bool operator!=(const Matrix& matrix) const;

    operator double();

    MatrixRow& operator[](int n);

    friend std::ostream& operator<<(std::ostream& stream, const Matrix* matrix);
    friend std::ostream& operator<<(std::ostream& stream, Matrix matrix);
    friend std::istream& operator>>(std::istream& stream, const Matrix* matrix);
    Matrix& operator,(const Matrix& matrix);
    void RandomGenerate();
};