#include<iostream>
#include<cmath>
using namespace std;

double TriangleSquare(double a, double h)
{
    return a * h * 0.5;
}

double TriangleSquare(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return  sqrt(p * (p - a) * (p - b) * (p - c));
}
double TriangleSquare(float a, float b, float angle)
{
    return  0.5*(a*b*(sin(angle)));
}

int main(int argc, char* argv[])
{
    int a, b;
    float c;
    cin >> a >> b >> c;
    cout << TriangleSquare(a, b, c);
    return 0;
}
