#include<iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;
    int* arr = new int[number]{};
    for (int i = 0; i < number; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < number; i++)
    {
        if (arr[i] < arr[number - 1])
        {
            cout << i + 1;
            break;
        }
        if (arr[number - 2] == arr[number - 1])
        {
            cout << number - 1;
        }
    }
    return 0;
}
