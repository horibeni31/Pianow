cmake_minimum_required(VERSION 3.5)
project(Pianow VERSION 0.1 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_TESTING off)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
if(CMAKE_VERSION VERSION_LESS "3.7.0")
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SRC_FILES
  exerciseresult.h
  settings.cpp
  settings.h
  settingsdialog.cpp
  settingsdialog.h
  settingsdialog.ui
  staffwidget.cpp
  staffwidget.h
  staffwidget.ui
  main.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
  midicontroller.cpp
  midicontroller.h
  midimessage.cpp
  midimessage.h
  note.cpp
  note.h
  noteidentification.cpp
  noteidentification.h
  noteidentification.ui
)
list(TRANSFORM SRC_FILES PREPEND "src/")
add_executable(Pianow ${SRC_FILES} resources.qrc)
target_include_directories(Pianow PUBLIC src)
find_package(nlohmann_json 3.11.2 REQUIRED)

target_link_libraries(Pianow Qt5::Widgets rtmidi nlohmann_json::nlohmann_json)

install(TARGETS Pianow DESTINATION bin)

