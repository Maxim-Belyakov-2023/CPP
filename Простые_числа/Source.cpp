#include <iostream>
#include <cmath>
using namespace std;

bool is_simple(int number) {
	for (int i = 2; i < number; i++) {
		if (number % i == 0) {
			return false;
		}
	}
	if (number == 1) {
		return false;
	}
	return true;
}
int main() {
	int number,count;
	count = 0;
	int i = 1;
	cin >> number;
	while (count != number) {
		if (is_simple(i)) {
			cout << i << endl;
			count += 1;
		}
		i++;
	

	}
}