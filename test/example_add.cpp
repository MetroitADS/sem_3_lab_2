#include <gtest/gtest.h>

#include "example.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>

// Здесь должны быть ваши функции split, sort_ip_pool и filter_by_first_byte
// Примерные определения функций
std::vector<std::string> split(const std::string& str, char delimiter);
void sort_ip_pool(std::vector<std::vector<int>>& ip_pool);
std::vector<std::vector<int>> filter_by_first_byte(const std::vector<std::vector<int>>& ip_pool, int first_byte);

// Тест для функции split
TEST(IPFilterTests, SplitTest) {
    std::string input = "192.168.0.1";
    char delimiter = '.';
    std::vector<std::string> expected = { "192", "168", "0", "1" };

    auto result = split(input, delimiter);

    EXPECT_EQ(result, expected);
}
/*/
// Тест для функции sort_ip_pool
TEST(IPFilterTests, SortIpPoolTest) {
    std::vector<std::vector<int>> ip_pool = { {192, 168, 0, 2}, {10, 0, 0, 1}, {192, 168, 0, 1} };
    std::vector<std::vector<int>> expected = { {10, 0, 0, 1}, {192, 168, 0, 1}, {192, 168, 0, 2} };

    sort_ip_pool(ip_pool);

    EXPECT_EQ(ip_pool, expected);
}

// Тест для функции filter_by_first_byte
TEST(IPFilterTests, FilterByFirstByteTest) {
    std::vector<std::vector<int>> ip_pool = { {192, 168, 0, 1}, {10, 0, 0, 1}, {192, 168, 0, 2} };
    std::vector<std::vector<int>> expected = { {192, 168, 0, 1}, {192, 168, 0, 2} };

    auto result = filter_by_first_byte(ip_pool, 192);

    EXPECT_EQ(result, expected);
}
  //*/
//int main(int argc, char** argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}

 /*/
TEST(example, add) {
  double res;
  res = add_numbers(1.0, 2.0);
  ASSERT_NEAR(res, 3.0, 1.0e-11);
}
//*/