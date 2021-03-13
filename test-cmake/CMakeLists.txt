cmake_minimum_required(VERSION 3.14)

project(IoT-Dashboard LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(JSON_BuildTests OFF CACHE INTERNAL "")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick Mqtt REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Mqtt REQUIRED)

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)


include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")

add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})


file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/hdr/DBController/*.h
                  ${CMAKE_CURRENT_SOURCE_DIR}/hdr/Model/*.h
                      ${CMAKE_CURRENT_SOURCE_DIR}/hdr/Plugin/*.h
                      ${CMAKE_CURRENT_SOURCE_DIR}/hdr/View/*.h
                      ${CMAKE_CURRENT_SOURCE_DIR}/hdr/*.h)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/DBController/*.cpp
                      ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/*.cpp
                      ${CMAKE_CURRENT_SOURCE_DIR}/src/Plugin/*.cpp
                      ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)


source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES}) 

qt5_add_resources(QT_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/share/qml.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(IoT-Dashboard
            ${HEADERS} 
            ${SOURCES} 
            ${QT_RESOURCES}
    )
else()
    if(ANDROID)
        add_library(IoT-Dashboard SHARED
                ${HEADERS} 
                ${SOURCES} 
                ${QT_RESOURCES}
        )
    else()
        add_executable(IoT-Dashboard
                ${HEADERS} 
                ${SOURCES} 
                ${QT_RESOURCES}
        )
    endif()
endif()

target_compile_definitions(IoT-Dashboard
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(IoT-Dashboard
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Mqtt ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES})

  file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/share
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
