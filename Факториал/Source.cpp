#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int number, result = 1;
    cin >> number;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    if (number == 0) {
        result = 0;
    }
    cout << result;
}
