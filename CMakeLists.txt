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
set(HEADERS
  exerciseresult.h
  settings.h
  settingsdialog.h
  staffwidget.h
  mainwindow.h
  midicontroller.h
  midimessage.h
  note.h
  noteidentification.h
  userdata.h
)
set(SRC_FILES
  settings.cpp
  settingsdialog.cpp
  settingsdialog.ui
  staffwidget.cpp
  staffwidget.ui
  main.cpp
  mainwindow.cpp
  mainwindow.ui
  midicontroller.cpp
  midimessage.cpp
  note.cpp
  noteidentification.cpp
  noteidentification.ui
  userdata.cpp
)
list(TRANSFORM SRC_FILES PREPEND "src/")
list(TRANSFORM HEADERS PREPEND "src/")
add_executable(Pianow ${SRC_FILES} ${HEADERS} resources.qrc)
target_include_directories(Pianow PUBLIC src)
find_package(nlohmann_json 3.11.2 REQUIRED)
find_package(Qt5 COMPONENTS Sql Widgets REQUIRED)
target_link_libraries(Pianow Qt5::Widgets Qt5::Sql rtmidi nlohmann_json::nlohmann_json)

install(TARGETS Pianow DESTINATION bin)

