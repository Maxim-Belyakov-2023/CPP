/**
 * ��������� �������
 * ��������� ������� ������������ �� ���� ������, ��������� �������� �������� ������ �������.
 * 
 * ���������� ������� � ��������� ������
 * ���_������** ��������_������� = new ���_������*[���_��_�����];
 * for (unsigned i = 0; i < ���_��_�����; i++)
 *      ��������_�������[i] = new ���_������[���_��_��������];
 *
 * ��� ��������� � ���������� ������� � ������ ������� ����������� ����� ������, �� ������ ����� �������.
 * ������[�����_������][�����_�������]
 *
 * ������������ ������
 * for (unsigned i = 0; i < ���_��_�����; i++)
 *      delete[] ��������_�������[i];
 * delete[] ��������_�������;
 */

#include <iomanip>
#include <iostream>

void PrintMatrix(int** matrix, int rowCount, int columnCount)
{
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < columnCount; ++j)
        {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout<< std::endl;
}

int** GetMatrix(int rowCount, int columnCount)
{
    int** matr = new int*[rowCount];
    for (unsigned i = 0; i < rowCount; i++)
        matr[i] = new int[columnCount]{};
    return matr;
}

void DeleteMatrix(int** matrix, int rowCount, int columnCount)
{
    for (unsigned i = 0; i < rowCount; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void RandomFill(int** matrix, int rowCount, int columnCount)
{
    srand(time(0));
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < columnCount; ++j)
        {
            matrix[i][j] = rand() % 1000;
        }
    }
}

int SumDiag(int** matrix, int rowCount, int columnCount)
{
    int sum = 0;
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < columnCount; ++j)
        {
            if (i == j || i == columnCount - j - 1)
                sum += matrix[i][j];
        }
    }
    return sum;
}

int main(int argc, char* argv[])
{
    setlocale(0, "RU");
    int row = 6, col = 8;
    int** matr = GetMatrix(row, col);
    
    PrintMatrix(matr, row, col);
    std::cout << "����� ��������� ���������� = " << SumDiag(matr, row, col);
    DeleteMatrix(matr, row, col);
    return 0;
}
