// test_ip_filter.cpp
#include "ip_filter.h"
#include <gtest/gtest.h>

TEST(SplitTest, BasicTests) {
    // Создаем временные объекты для ожидаемых значений
    std::vector<std::string> splitExpected1{ "192", "168", "1", "1" };
    std::vector<std::string> splitExpected2{ "10", "0", "0", "1" };
    std::vector<std::string> splitExpected3{ "255", "255", "255", "255" };

    EXPECT_EQ(split("192.168.1.1", '.'), splitExpected1);
    EXPECT_EQ(split("10.0.0.1", '.'), splitExpected2);
    EXPECT_EQ(split("255.255.255.255", '.'), splitExpected3);
    EXPECT_EQ(split("", '.'), std::vector<std::string>{""});
}

TEST(SortIpPoolTest, BasicTests) {
    //Входные тесты
    std::vector<std::vector<std::string>> ip_pool = {
        {"192", "168", "1", "1"},
        {"10", "0", "0", "1"},
        {"255", "255", "255", "255"},
        {"172", "16", "0", "1"}
    };

    sort_ip_pool(ip_pool);

    // Должно выйти
    std::vector<std::string> expected1{ "255", "255", "255", "255" };
    std::vector<std::string> expected2{ "192", "168", "1", "1" };
    std::vector<std::string> expected3{ "172", "16", "0", "1" };
    std::vector<std::string> expected4{ "10", "0", "0", "1" };

    EXPECT_EQ(ip_pool[0], expected1);
    EXPECT_EQ(ip_pool[1], expected2);
    EXPECT_EQ(ip_pool[2], expected3);
    EXPECT_EQ(ip_pool[3], expected4);
}

TEST(FilterByFirstByteTest, BasicTests) {
    std::vector<std::vector<std::string>> ip_pool = {
        {"192", "168", "1", "1"},
        {"10", "0", "0", "1"},
        {"46", "70", "0", "1"},
        {"46", "100", "0", "1"}
    };

    //вовод только 46
    auto filtered = filter_by_first_byte(ip_pool, 46);
    EXPECT_EQ(filtered.size(), 2);

    // Должно выйти
    std::vector<std::string> expected1{ "46", "70", "0", "1" };
    std::vector<std::string> expected2{ "46", "100", "0", "1" };

    EXPECT_EQ(filtered[0], expected1);
    EXPECT_EQ(filtered[1], expected2);
}

TEST(FilterByFirstAndSecondBytesTest, BasicTests) {
    std::vector<std::vector<std::string>> ip_pool = {
        {"192", "168", "1", "1"},
        {"10", "0", "0", "1"},
        {"46", "70", "0", "1"},
        {"46", "100", "0", "1"}
    };

    auto filtered = filter_by_first_and_second_bytes(ip_pool, 46, 70);
    EXPECT_EQ(filtered.size(), 1);

    std::vector<std::string> expected{ "46", "70", "0", "1" };

    EXPECT_EQ(filtered[0], expected);
}

TEST(FilterAnyByteTest, BasicTests) {
    std::vector<std::vector<std::string>> ip_pool = {
        {"192", "168", "1", "1"},
        {"10", "0", "0", "1"},
        {"46", "70", "0", "1"},
        {"46", "100", "0", "1"}
    };

    auto filtered = filter_any_byte(ip_pool, 100);
    EXPECT_EQ(filtered.size(), 1);

    std::vector<std::string> expected{ "46", "100", "0", "1" };

    EXPECT_EQ(filtered[0], expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
