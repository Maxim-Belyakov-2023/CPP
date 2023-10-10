/**
 * ƒвумерные массивы
 * ƒвумерные массивы представл€ют из себ€ массив, элеметами которого €вл€ютс€ другие массивы.
 * 
 * ќбъ€вление массива и выделение пам€ти
 * тип_данных** название_массива = new тип_данных*[кол_во_строк];
 * for (unsigned i = 0; i < кол_во_строк; i++)
 *      название_массива[i] = new тип_данных[кол_во_столбцов];
 *
 * ѕри обращении к двумерному массиву в первых скобках указываетс€ номер строки, во вторых номер столбца.
 * массив[номер_строки][номер_столбца]
 *
 * ќсвобождение пам€ти
 * for (unsigned i = 0; i < кол_во_строк; i++)
 *      delete[] название_массива[i];
 * delete[] название_массива;
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
    RandomFill(matr, row, col);
    PrintMatrix(matr, row, col);
    std::cout << "—умма элементов диагоналей = " << SumDiag(matr, row, col);
    DeleteMatrix(matr, row, col);
    return 0;
}
