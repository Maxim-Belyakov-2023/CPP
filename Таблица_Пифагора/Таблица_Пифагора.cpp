#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    cout << " ";
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << i * j << " ";
        }
        cout << endl;
    }

}