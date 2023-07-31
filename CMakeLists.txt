cmake_minimum_required(VERSION 3.5)
project(Pianow VERSION 0.1 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_TESTING off)
add_subdirectory(rtmidi)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH "/usr/bin")
if(CMAKE_VERSION VERSION_LESS "3.7.0")
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Pianow
  src/settings.cpp
  src/settings.h
  src/settingsdialog.cpp
  src/settingsdialog.h
  src/settingsdialog.ui
  src/staffwidget.cpp
  src/staffwidget.h
  src/staffwidget.ui
  src/main.cpp
  src/mainwindow.cpp
  src/mainwindow.h
  src/mainwindow.ui
  src/midicontroller.cpp
  src/midicontroller.h
  src/midimessage.cpp
  src/midimessage.h
  src/note.cpp
  src/note.h
  src/noteidentification.cpp
  src/noteidentification.h
  src/noteidentification.ui
  resources.qrc
)
target_include_directories(Pianow PUBLIC src)

target_link_libraries(Pianow Qt5::Widgets rtmidi)
install(TARGETS Pianow DESTINATION bin)

