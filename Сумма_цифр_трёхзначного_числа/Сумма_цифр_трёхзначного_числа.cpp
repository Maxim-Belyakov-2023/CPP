/**
 * Пользователь вводит число.
 * Необходимо вывсти на экран сумму его цифр.
 * Предполагается, что число трёхзначное.
 */
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int number;
    cin >> number;
    int sum = 0;
    sum += number % 10;
    sum += (number / 10) % 10;
    sum += number / 100;
    cout << sum;

    return 0;
}
