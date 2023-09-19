#include <iostream>
using namespace std;

int max_digit(int num)
{
    if (num / 10 == 0)
    {
        return num;
    }

    return max(max_digit(num / 10), num % 10);
}

int max_digit2(int num, int max_num)
{
    if (num > 0)
    {
        return max_digit2(num / 10, (num % 10 > max_num ? num % 10 : max_num));
    }
    return max_num;
}

int main(int argc, char* argv[])
{
    int number;
    cin >> number;
    cout << max_digit2(number, 0);
}
