cmake_minimum_required(VERSION 3.10)
project(SmartTicket LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Recherche des modules Qt5 nécessaires
find_package(Qt5 REQUIRED COMPONENTS Core Sql)

add_executable(smartticket
    src/main.cpp
    src/database.cpp
    src/ticket.cpp
)

target_include_directories(smartticket PRIVATE src)

target_link_libraries(smartticket
    Qt5::Core
    Qt5::Sql
)
