# CMakeList.txt: проект CMake для sem_3_lab_2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.

add_executable (sem_3_lab_2 "sem_3_lab_2.cpp" "sem_3_lab_2.h")

if (CMAKE_VERSION VERSION_GREATER 3.14)
  set_property(TARGET sem_3_lab_2 PROPERTY CXX_STANDARD 20)
endif()
#set(GTEST_ROOT "C:/lib/googletest-1.15.2/build")


#find_package(GTest REQUIRED CONFIG PATHS ${GTEST_ROOT} NO_DEFAULT_PATH)
include_directories(${GTEST_INCLUDE_DIRS})
#add_executable(test_ip_filter test_ip_filter.cpp)
#target_link_libraries(test_ip_filter GTest::gtest GTest::gtest_main)