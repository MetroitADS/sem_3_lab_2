// ip_filter.h
#ifndef IP_FILTER_H
#define IP_FILTER_H

#include <string>
#include <vector>
#include <algorithm>

//разделение на части
std::vector<std::string> split(const std::string& str, char d);

//сортировка
void sort_ip_pool(std::vector<std::vector<std::string>>& ip_pool);

//первому байту
std::vector<std::vector<std::string>> filter_by_first_byte(const std::vector<std::vector<std::string>>& ip_pool, int byte);

//второму байтам
std::vector<std::vector<std::string>> filter_by_first_and_second_bytes(const std::vector<std::vector<std::string>>& ip_pool, int byte1, int byte2);

//любой байт
std::vector<std::vector<std::string>> filter_any_byte(const std::vector<std::vector<std::string>>& ip_pool, int byte);

#endif // IP_FILTER_H
