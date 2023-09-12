#include <iostream>
using namespace std;
int sum_digit(int number)
{
    if (number > 0)
    {
        return sum_digit(number/10) + number%10;
    }
    return 0;
}
int main(int argc, char* argv[])
{
    int number;
    cin >> number;
    cout<< sum_digit(number);
    return 0;
}
