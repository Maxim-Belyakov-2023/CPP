#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num,max,chain;
    chain = 0;
    cin>> num;
    max = num;
    while (num != 0) {
        if (max < num) {
            max = num;
            chain = 0;
        }
        if (max = num) {
            chain += 1;
        }

        cin >> num;
    }
    cout << max << " " << chain;

}
