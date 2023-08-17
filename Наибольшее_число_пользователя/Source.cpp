#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, max, chain,maxpos1,maxpos2;
    chain = 0;
    cin>> num;
    max = num;
    while (num != 0) {
        if (max < num) {
            max = num;
            maxpos1 = chain;
        }
        if (num == max) {
            maxpos2 = chain;
        }
        chain += 1;
        cin >> num;
    }
    cout << max << " " << maxpos1<<" " << maxpos2;

}