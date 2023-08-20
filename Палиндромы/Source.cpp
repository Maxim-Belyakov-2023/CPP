#include <iostream>
#include <cmath>
using namespace std;
bool is_palindrome(int number) {
	int temp,num1;
	temp = 0;
	num1 = number;
	while (number > 0) {
		temp = (temp * 10) + (number % 10);
		number /= 10;
	}
	if (temp == num1) {
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