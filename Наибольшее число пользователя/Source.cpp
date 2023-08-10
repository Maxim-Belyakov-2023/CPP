#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num,max,chain,maxchain;
    chain = 0;
    cin>> num;
    max = num;
    while (num != 0) {
        chain += 1;
        if (max < num) {
            max = num;
            maxchain = chain;
        }
        cin >> num;
    }
    cout << max <<" " << maxchain;

}
