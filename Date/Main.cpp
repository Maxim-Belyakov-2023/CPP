#include<iostream>
#include"Date.h"
using namespace std;
int main(int argc, char* argv[]){

    int day,month,year;
    cin >> day >> month >> year;
    Date date(day,month,year);
    date.AddDay();
    date.Print();
}
