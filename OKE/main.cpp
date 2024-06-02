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
        std::cout << "Данные записаны в файл " << filename << "\n";
    }
    else
    {
        std::cout << "Ошибка при открытии файла!" << "\n";
    }
}

int main() 
{
    setlocale(LC_ALL, "ru");
    std::string product_name, quantity, price;
    int choice;
    bool append;

    std::cout << "Выберите файл для записи:\n";
    std::cout << "1) Название товара\n";
    std::cout << "2) Количество\n";
    std::cout << "3) Цена\n";
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
        std::cout << "Неверный выбор\n";
    }


    std::cout << "Введите данные для записи: ";
    std::cin.ignore();
    std::getline(std::cin, (choice == 1) ? product_name : (choice == 2) ? quantity : price);

    std::cout << "Дополнить (1) или перезаписать (0) файл? ";
    std::cin >> append;

    writeToFile(filename, (choice == 1) ? product_name : (choice == 2) ? quantity : price, append);
       
    return 0;
}