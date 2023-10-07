#include<iostream>
using namespace std;
void K_M_Reverse(int* arr,int K, int M)
{
    for (int i =0; i < M/2; i++)
    {
        int temp = arr[K+i];
        arr[K+i]=arr[M-i];
        arr[M-i]=temp;
    }
}
int main(int argc, char* argv[])
{
    int number,K,M;
    cin >> number;
    int* arr = new int[number];
    for (int i = 0; i<number;i++)
    {
        cin >> arr[i];
    }
    cin >> K >> M;
    K-=1;
    M-=1;
    K_M_Reverse(arr,K,M);
    for (int i =0; i<number;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
