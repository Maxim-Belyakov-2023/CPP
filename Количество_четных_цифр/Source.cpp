#include <iostream>
#include <cmath>
using namespace std;

int even_number(int number)
{
    if (number > 0)
    {
        return ((number % 10) % 2 == 0) + even_number(number / 10);
    }
    return 0;
}

int main()
{
    int number;
    cin >> number;
    cout << even_number(number);
}
