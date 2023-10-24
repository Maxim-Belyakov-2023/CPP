#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

void PrintMatrix(int** matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void ChessFill(int** matrix, int row, int column)
{
    int count = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matrix[i][j] = count;
            if (count == 0)
            {
                count = 1;
            }
            else
            {
                count = 0;
            }
        }
    }
}

void CrossFill(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j == size - i or j == i)
            {
                matrix[i][j] = 1;
            }
        }
    }
}

int** CreateMatrix(int row, int column)
{
    int** matrix = new int*[row];
    for (unsigned i = 0; i < row; i++)
    {
        matrix[i] = new int[column]{};
    }
    return matrix;
}

int main(int argc, char* argv[])
{
    int row, column;
    cin >> row >> column;
    int** matr = CreateMatrix(row, column);
    ChessFill(matr, row, column);
    PrintMatrix(matr, row, column);

    return 0;
}
