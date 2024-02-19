#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[])
{
    int n;
    n = 0;
    int a[1];
    try
    {
        std::cout << 1 / n;
    }
    catch(std::runtime_error ex)
    {
        std::cout << ex.what();
    }
    return 0;
}
