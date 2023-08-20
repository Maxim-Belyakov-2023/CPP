#include <iostream>
#include <cmath>
using namespace std;
bool is_palindrome(int number) {
	if (number % 10 == (number / 1000)%10 && (number / 100) % 10 == (number / 10) % 10) {
		return true;
	}
	return false;
}
int main() {
	int num1, num2;
	cin >> num1 >> num2;
	while (num1 != num2) {
		if (is_palindrome(num1)) {
			cout << num1 << endl;
		}
		num1++;

	}
}