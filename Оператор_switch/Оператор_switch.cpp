#include <iostream>
#include <clocale>
#include <Windows.h>

int main(int argc, char* argv[])
{
    /**
     *  switch(<значение или выражение>)
     *  {
     *      case <значение 1>:
     *          <операторы>
     *          break;
     *      case <значение 2>:
     *          <операторы>
     *          break;
     *      ...
     *      default:
     *          <операторы>
     *          break;
     *  }
     *
     *  switch - проверяет значение и сравнивает его со всеми case,
     *           если есть совпадения, то выполняются соответствующие
     *           операторы, если нет, то блок default, если он есть.
     */
    setlocale(LC_ALL, "Russian");
    int day = 45;
    switch (day)
    {
    case 1:
        std::cout << "Monday";
        break;
    case 2:
        std::cout << "Tuesday";
        break;
    case 3:
        std::cout << "Wednesday";
        break;
    case 4:
        std::cout << "Thursday";
        break;
    default:
        std::cout << "Error!";
        break;
    }
    return 0;
}
