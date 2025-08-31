cmake_minimum_required(VERSION 3.16)
project(3DRenderer)

set(CMAKE_CXX_STANDARD 23)  # C++26 henüz tam destekli değil, 23 kullan

# SDL3 header ve lib dizinlerini elle belirt
set(SDL3_INCLUDE_DIR "C:/libs/SDL/include")
set(SDL3_LIBRARY "C:/libs/SDL/build/Release/SDL3.lib")

# Header dosyaları için
include_directories(${SDL3_INCLUDE_DIR})

# main.cpp yerine senin dosyanı yaz
add_executable(3DRenderer main.cpp
        Renderer3D.cpp
        Renderer3D.h
)

# SDL3.lib ile linkle
target_link_libraries(3DRenderer PRIVATE ${SDL3_LIBRARY})
