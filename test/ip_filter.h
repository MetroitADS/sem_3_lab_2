// ip_filter.h
#ifndef IP_FILTER_H
#define IP_FILTER_H

#include <string>
#include <vector>
#include <algorithm>

// Функция разделения строки на части по заданному разделителю
std::vector<std::string> split(const std::string& str, char d);

// Функция для обратной лексикографической сортировки IP-адресов
void sort_ip_pool(std::vector<std::vector<std::string>>& ip_pool);

// Функция фильтрации по первому байту
std::vector<std::vector<std::string>> filter_by_first_byte(const std::vector<std::vector<std::string>>& ip_pool, int byte);

// Функция фильтрации по первому и второму байтам
std::vector<std::vector<std::string>> filter_by_first_and_second_bytes(const std::vector<std::vector<std::string>>& ip_pool, int byte1, int byte2);

// Функция фильтрации по любому байту
std::vector<std::vector<std::string>> filter_any_byte(const std::vector<std::vector<std::string>>& ip_pool, int byte);

#endif // IP_FILTER_H
