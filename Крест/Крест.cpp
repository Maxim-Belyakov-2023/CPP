#include <iostream>
#include <iomanip>
using namespace std;
void Cross(int** matrix, int columnCount)
{
    for(int i = 0 ; i< columnCount; i++)
    {
        for (int j = 0; j<columnCount; j++)
        {
            if(j==columnCount-i or j==i)
            {
                matrix[i][j] = 1;
            }
        }
    }
}
void printMatrix(int** matrix, int columnCount)
{
    for (int i = 0; i<columnCount;i++)
    {
        for (int j = 0 ; j<columnCount;j++)
        {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int** getMatrix (int columnCount)
{
    int** matr = new int*[columnCount];
    
    for (unsigned i = 0; columnCount<i ; i++)
    {
        matr[i]= new int[columnCount]{};
    }
    return matr;
}
int main(int argc, char* argv[])
{
    int columnCount = 7;
    int** matrix = getMatrix(columnCount);
    Cross(matrix,columnCount);
    printMatrix(matrix,columnCount);
    return 0;
}
