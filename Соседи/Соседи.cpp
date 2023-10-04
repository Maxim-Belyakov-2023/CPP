#include  <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int size, j, count;
    count = 0;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> j;
        arr[i] = j;
    }
    for (int i = 1; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
        {
            count += 1;
        }
    }
    cout << count;
    return 0;
}
