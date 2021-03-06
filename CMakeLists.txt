cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(ExplicitCAD)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL REQUIRED)
find_package(QScintilla REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Threads REQUIRED)

set(SRCS main.cpp mainwindow.cpp backdrop.cpp glmesh.cpp mesh.cpp loader.cpp canvas.cpp)
set(RESOURCES explicitcad.qrc gl/gl.qrc)

add_executable(explicitCAD ${SRCS} ${RESOURCES})
target_link_libraries(explicitCAD Qt5::Core Qt5::Gui Qt5::Widgets Qt5::OpenGL QScintilla::QScintilla OpenGL::GL Threads::Threads)
