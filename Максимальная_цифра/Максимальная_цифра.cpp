#include <iostream>
using namespace std;

int max_digit(int num)
{
    if (num/10==0)
    {
        return num;
    }
    else
    {
        return max(max_digit(num/10),num%10);
    }
    
}
int main(int argc, char* argv[])
{
    int number,max,temp;
    max = 0;
    temp = 0;
    cin >> number;
    cout << max_digit(number);
}
