#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int number;
    cin >> number;
    if (number % 100 >= 11 && number % 100 <= 14)
        cout << number << " ������" << endl;
    else if (number % 10 == 1)
    {
        cout << number << " ����" << endl;
    }
    else if (number % 10 >= 2 && number % 10 < 5)
    {
        cout << number << " �����" << endl;
    }
    else
    {
        cout << number << " ������" << endl;
    }
}
