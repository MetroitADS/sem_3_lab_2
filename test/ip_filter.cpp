// ip_filter.cpp
#include "ip_filter.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
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

void sort_ip_pool(std::vector<std::vector<std::string>>& ip_pool)
{
    std::sort(ip_pool.begin(), ip_pool.end(), [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
        return std::lexicographical_compare(b.begin(), b.end(), a.begin(), a.end());
        });
}

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
