
#include <iomanip>
#include <iostream>

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RU");
    /**
     *  setw(<ширина в пробелах>) - отводит для вывода определённый размер
     *  setprecision(<кол-во значений после запятой>) - устанавливает размер вещественной части 
     *
     *  Флаги
     *  left  - выравнивает содержимое по левому краю
     *  fixed - фиксирует кол-во знаков после запятой
     */
    std::cout.setf(std::ios::fixed);
    std::cout << "Градусы" << "|" << "Sin" << std::endl;
    for (int i = 0; i < 360; i++)
    {
        std::cout << std::left << std::setw(7) << i << "|" << std::setprecision(4) << sin(i) << std::endl;
    }
    return 0;
}
