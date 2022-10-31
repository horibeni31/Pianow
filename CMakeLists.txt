cmake_minimum_required(VERSION 3.16)
project (Pianow)

add_executable(Pianow main.cpp)
find_package(Qt5 CONFIG REQUIRED COMPONENTS Core Gui Widgets)
target_link_libraries(Pianow PUBLIC Qt::Core Qt::Gui Qt::Widgets)