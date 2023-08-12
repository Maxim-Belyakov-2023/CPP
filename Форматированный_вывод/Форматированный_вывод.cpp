
#include <iomanip>
#include <iostream>

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RU");
    /**
     *  setw(<������ � ��������>) - ������� ��� ������ ����������� ������
     *  setprecision(<���-�� �������� ����� �������>) - ������������� ������ ������������ ����� 
     *
     *  �����
     *  left  - ����������� ���������� �� ������ ����
     *  fixed - ��������� ���-�� ������ ����� �������
     */
    std::cout.setf(std::ios::fixed);
    std::cout << "�������" << "|" << "Sin" << std::endl;
    for (int i = 0; i < 360; i++)
    {
        std::cout << std::left << std::setw(7) << i << "|" << std::setprecision(4) << sin(i) << std::endl;
    }
    return 0;
}
