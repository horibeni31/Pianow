cmake_minimum_required(VERSION 3.5)
project (Pianow VERSION 0.1 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

configure_file("bass.png" "bass.png" COPYONLY)
configure_file("treble.png" "treble.png" COPYONLY)


add_executable(Pianow main.cpp 
                      widgets/mainWindow.cpp
                      widgets/staff.cpp
                      exercises/noteIdentification.cpp
                      exercises/exercise.cpp
                      midi/midiController.cpp
                      midi/midiMessage.cpp
                      midi/note.cpp
                      
                        )

target_link_libraries(Pianow PUBLIC Qt5::Widgets rtmidi)
