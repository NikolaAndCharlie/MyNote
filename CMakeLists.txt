cmake_minimum_required(VERSION 3.5)
project(MyNote)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CURRENT_INCLUDE ON)


find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

set(Qt_LIB Qt5::Widgets Qt5::Core Qt5::Gui)
set(APP_RC_FILE src/MyNote.rc)


file(GLOB_RECURSE HEAD src/*.h)
file(GLOB_RECURSE SRC src/*.cpp)


add_executable(MyNote WIN32 ${HEAD} ${SRC} ${APP_RC_FILE})
target_link_libraries(MyNote ${Qt_LIB})





