#include<iostream>
using namespace std;

 int main(){
	int height,number,temp=0;
	cin >> number;
	int* arr = new int[number] {};
	for (int i = 0; i < number; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < number; i++) {
		temp = arr[number];
		if (arr[i] < temp) {
			cout << i+1;
			break;

		}
		else if (arr[i] = temp) {
			cout << i + 2;
			break;
		}
	}
	return 0;

	


}