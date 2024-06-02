#include <iostream>
#include <fstream>
#include <string>

void writeToFile(const std::string& filename, const std::string& data, bool append) 
{
    std::ofstream file;
    if (append) 
    {
        file.open(filename, std::ofstream::app);
    }


    if (file.is_open()) 
    {
        file << data << "\n";
        file.close();
        std::cout << "������ �������� � ���� " << filename << "\n";
    }
    else
    {
        std::cout << "������ ��� �������� �����!" << "\n";
    }
}

int main() 
{
    setlocale(LC_ALL, "ru");
    std::string product_name, quantity, price;
    int choice;
    bool append;

    std::cout << "�������� ���� ��� ������:\n";
    std::cout << "1) �������� ������\n";
    std::cout << "2) ����������\n";
    std::cout << "3) ����\n";
    std::cin >> choice;

    std::string filename;
    if (choice)
    {
    filename = "product_name.txt"; 
    }
    else if (choice == 2)
    {
        filename = "quantity.txt"; 
    }
    else if (choice == 3)
    {
        filename = "price.txt";
    }
    else
    {
        std::cout << "�������� �����\n";
    }


    std::cout << "������� ������ ��� ������: ";
    std::cin.ignore();
    std::getline(std::cin, (choice == 1) ? product_name : (choice == 2) ? quantity : price);

    std::cout << "��������� (1) ��� ������������ (0) ����? ";
    std::cin >> append;

    writeToFile(filename, (choice == 1) ? product_name : (choice == 2) ? quantity : price, append);
       
    return 0;
}