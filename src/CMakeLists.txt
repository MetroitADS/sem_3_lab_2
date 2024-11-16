# CMakeList.txt: проект CMake для sem_3_lab_2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.

add_library(example)

target_sources(example
  PRIVATE
    sem_3_lab_2.cpp
  PUBLIC
    sem_3_lab_2.h
  )

target_include_directories(example
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(example
    PUBLIC
      "--coverage"
    )
  target_link_options(example
    INTERFACE
      "--coverage"
    )
endif()
#set(GTEST_ROOT "C:/lib/googletest-1.15.2/build")


#find_package(GTest REQUIRED CONFIG PATHS ${GTEST_ROOT} NO_DEFAULT_PATH)
include_directories(${GTEST_INCLUDE_DIRS})
#add_executable(test_ip_filter test_ip_filter.cpp)
#target_link_libraries(test_ip_filter GTest::gtest GTest::gtest_main)