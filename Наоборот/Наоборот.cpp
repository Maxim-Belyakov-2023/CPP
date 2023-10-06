#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int number,chislo;
    cin >> number;
    int* arr = new int[number]{};
    for (int j = number-1; j>=0; j--)
    {
        cin >> chislo;
        arr[j]=chislo;
    }
    for (int i = 0; i<number; i++)
    {
        cout<<arr[i]<< " ";
    }
    
    
    return 0;
}
