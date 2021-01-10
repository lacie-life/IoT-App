cmake_minimum_required(VERSION 3.5)

project(IoT-Net LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the Qt libraries for Qt Quick/QML
find_package(Qt5 REQUIRED Qml Quick Gui)

# add the qml.qrc file
qt5_add_resources(qml_QRC src/qml.qrc)

# add source files
set(SOURCE
        ${SOURCE}
        src/main.cpp
        src/test.cpp
        src/test.h
)

# Tell CMake to create the helloworld executable
add_executable(IoT-Net ${SOURCE} ${qml_QRC})

# Use the Qml/Quick modules from Qt 5.
target_link_libraries(IoT-Net Qt5::Qml Qt5::Quick)
