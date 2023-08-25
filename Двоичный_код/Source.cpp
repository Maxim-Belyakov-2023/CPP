#include <iostream>
#include <cmath>
using namespace std;
int binary_num( int number) {
	if (number != 0) {
		binary_num(number/2);
		cout << abs(number%2);
	}
	return 0;
}
int main() {
	int number;
	cin >> number;
	if (number < 0) {
		cout << "-";
	}
	binary_num(number);
}