#include <iostream>
#include <cmath>
using namespace std;
bool is_perfect(int number) {
	int result = 0;
	for (int i = 1; i < number; i++) {
		if (number % i == 0) {
			result += i;
		}
	}
	if (result != number) {
		return false;
	}
	return true;
}
int main() {
	int count;
	cin >> count;
	int i = 2;
	int j = 0;
	while ( j < count) {
		if (is_perfect(i)) {
			cout << i << " ";
			j++;
		}
		i++;
	}
}