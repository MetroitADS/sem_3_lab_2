#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// Функция разделения строки на части по заданному разделителю
std::vector<std::string> split(const std::string& str, char d)
{
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);

    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));
    return r;
}

// Функция для обратной лексикографической сортировки IP-адресов
void sort_ip_pool(std::vector<std::vector<std::string>>& ip_pool)
{
    std::sort(ip_pool.begin(), ip_pool.end(), [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
        return std::lexicographical_compare(b.begin(), b.end(), a.begin(), a.end());
        });
}

// Функция фильтрации по первому байту
std::vector<std::vector<std::string>> filter_by_first_byte(const std::vector<std::vector<std::string>>& ip_pool, int byte)
{
    std::vector<std::vector<std::string>> filtered;
    for (const auto& ip : ip_pool)
    {
        if (!ip.empty() && std::stoi(ip[0]) == byte)
        {
            filtered.push_back(ip);
        }
    }
    return filtered;
}

// Функция фильтрации по первому и второму байтам
std::vector<std::vector<std::string>> filter_by_first_and_second_bytes(const std::vector<std::vector<std::string>>& ip_pool, int byte1, int byte2)
{
    std::vector<std::vector<std::string>> filtered;
    for (const auto& ip : ip_pool)
    {
        if (!ip.empty() && ip.size() > 1 && std::stoi(ip[0]) == byte1 && std::stoi(ip[1]) == byte2)
        {
            filtered.push_back(ip);
        }
    }
    return filtered;
}

// Функция фильтрации по любому байту
std::vector<std::vector<std::string>> filter_any_byte(const std::vector<std::vector<std::string>>& ip_pool, int byte)
{
    std::vector<std::vector<std::string>> filtered;
    for (const auto& ip : ip_pool)
    {
        if (std::find_if(ip.begin(), ip.end(), [byte](const std::string& part) { return std::stoi(part) == byte; }) != ip.end())
        {
            filtered.push_back(ip);
        }
    }
    return filtered;
}

int main()
{

        std::vector<std::vector<std::string>> ip_pool;

        // Чтение IP-адресов из файла ip_filter.tsv
        std::ifstream file("C:/Users/Metroit/source/repos/sem_3_lab_2/ip_filter.tsv");
        if (!file.is_open()) {
            throw std::runtime_error("Could not open the file.");
        }

        for (std::string line; std::getline(file, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.')); //192.168.1.1 станет { "192", "168", "1", "1" }
        }

        file.close(); // Закрываем файл после чтения

        // Сортировка IP-адресов в обратном лексикографическом порядке
        sort_ip_pool(ip_pool);

        // Вывод отсортированных IP-адресов
        std::cout << "Sorted IP addresses:\n";
        for (const auto& ip : ip_pool)
        {
            for (const auto& ip_part : ip)
            {
                if (ip_part != ip.front())
                {
                    std::cout << ".";
                }
                std::cout << ip_part;
            }
            std::cout << std::endl;
        }

        // Пример фильтрации по первому байту
        auto filtered_first_byte = filter_by_first_byte(ip_pool, 1);
        std::cout << "\nFiltered by first byte (1):\n";
        for (const auto& ip : filtered_first_byte)
        {
            for (const auto& ip_part : ip)
            {
                if (ip_part != ip.front())
                {
                    std::cout << ".";
                }
                std::cout << ip_part;
            }
            std::cout << std::endl;
        }

        // Пример фильтрации по первому и второму байтам
        auto filtered_first_and_second_bytes = filter_by_first_and_second_bytes(ip_pool, 46, 70);
        std::cout << "\nFiltered by first byte (192) and second byte (168):\n";
        for (const auto& ip : filtered_first_and_second_bytes)
        {
            for (const auto& ip_part : ip)
            {
                if (ip_part != ip.front())
                {
                    std::cout << ".";
                }
                std::cout << ip_part;
            }
            std::cout << std::endl;
        }

        // Пример фильтрации по любому байту
        auto filtered_any_byte = filter_any_byte(ip_pool, 46);
        std::cout << "\nFiltered by any byte (255):\n";
        for (const auto& ip : filtered_any_byte)
        {
            for (const auto& ip_part : ip)
            {
                if (ip_part != ip.front())
                {
                    std::cout << ".";
                }
                std::cout << ip_part;
            }
            std::cout << std::endl;
        }

}
