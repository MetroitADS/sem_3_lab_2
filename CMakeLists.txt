cmake_minimum_required(VERSION 3.13)
project(sem_3_lab_2 LANGUAGES CXX)

set(This Exmple)

# Установите стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Поместите бинарники и библиотеки в соответствии со стандартами GNU
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# Проверка наличия gcov
find_program(GCOV_PATH gcov)
if(NOT GCOV_PATH)
    message(FATAL_ERROR "Code coverage analysis requires gcov!")
endif()

# Включение подкаталогов
add_subdirectory(src)
enable_testing()
add_subdirectory(test)
add_executable(helloworld src/sem_3_lab_2.cpp)
# Установите цели для бинарников и заголовков
install(TARGETS helloworld  # Замените на фактическое имя вашей цели
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES your_header_file.h  # Замените на ваши заголовочные файлы
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Настройка CPack для генерации пакетов
include(CPack)
set(CPACK_GENERATOR "DEB;PKG")  # Укажите форматы пакетов, которые вы хотите создать
set(CPACK_PACKAGE_NAME "helloworld")  # Замените на ваше имя пакета
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")  # Установка версии пакета
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <youremail@example.com>")  # Укажите свою почту
