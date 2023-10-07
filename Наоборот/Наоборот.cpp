#include <iostream>
using namespace std;

void Reverse(int* array, int size)
{
    int temp = 0;
    for (int i = 0; i < size / 2; i++)
    {
        temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

int main(int argc, char* argv[])
{
    int number;
    cin >> number;
    int* arr = new int[number];
    for (int i = 0; i < number; i++)
        cin >> arr[i];

    Reverse(arr, number);
    for (int i = 0; i < number; i++)
    {
        cout << arr[i] << " ";
    }
}
