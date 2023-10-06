#include <iostream>
using namespace std;

void Reverse(int* array, int size)
{
    // TODO
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
        cout << arr[i] << " ";
    return 0;
}
