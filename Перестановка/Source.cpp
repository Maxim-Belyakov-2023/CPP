#include<iostream>
using namespace std;

int main() {
	int count, number,temp=0;
	cin >> count;
	int* arr = new int[count] {};
	for (int i = 0; i < count; i++) {
		cin >> number;
		arr[i] = number;
	}
	for (int j = 0; j < count-1; j++) {
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j++;
		
	}
	for (int i = 0; i < count; i++) {
		cout << arr[i];
	}
}