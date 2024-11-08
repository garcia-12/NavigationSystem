cmake_minimum_required(VERSION 3.16)

project(Praktikum02_01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Praktikum02_01 main.cpp
    ort.h ort.cpp
    adresse.h adresse.cpp
    pol.h pol.cpp
    navigationsystem.h navigationsystem.cpp)

include(GNUInstallDirs)
install(TARGETS Praktikum02_01
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
