#include <iostream>
#include <cmath>
using namespace std;
int even_number(int number) {
	int count = 0;
	if (number != 0) {
		even_number(number / 10);
	}
	if (number % 2 == 0) {
		count++;
	}
	cout << count;
	return 0;
}
int main() {
	int number;
	cin >> number;
	even_number(number);

}