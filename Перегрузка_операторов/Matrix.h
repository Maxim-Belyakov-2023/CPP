#pragma once
#include <iomanip>

class Matrix
{
private:
    double **matr;
    int size;
public:
    Matrix(int size);
    Matrix(double** matrix, int size);

    // / * - + %
    Matrix operator+(Matrix matrix) const;
    Matrix operator+(double number) const;
    Matrix operator*(const Matrix* matrix) const;

    // ++(postfix) --(postfix) ++(prefix) --(prefix)
    // без параметров - prefix
    Matrix& operator++();
    // c параметром - postfix
    Matrix& operator++(int) const;

    // > < >= <= == !=
    bool operator==(const Matrix& matrix) const;
    bool operator!=(const Matrix& matrix) const;

    // ()
    operator double();

    // const double& operator[](int n) const;

    // << >>
    friend std::ostream& operator<<(std::ostream& stream, const Matrix* matrix);
    friend std::ostream& operator<<(std::ostream& stream, Matrix matrix);
    friend std::istream& operator>>(std::istream& stream, const Matrix* matrix);

    void RandomGenerate() const;
    ~Matrix();
};

// =
// && || !
// []

// & | << >> ~ ^
// += -= *= /= %= |= &= <<= >>= ^= ~=
// * -> new delete ,