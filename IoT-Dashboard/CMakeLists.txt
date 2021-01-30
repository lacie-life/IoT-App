cmake_minimum_required(VERSION 3.14)

project(IoT-Dashboard LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(JSON_BuildTests OFF CACHE INTERNAL "")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package(...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick Mqtt REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Mqtt REQUIRED)

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)

set(PROJECT_SOURCES
        src/main.cpp
        src/DBController/QMongoDB.cpp
        src/AppEngine.cpp
        src/Model/Constants_Def.cpp
        src/Plugin/QCircleMeter.cpp
        src/Plugin/SensorsMQTT.cpp
        src/Plugin/QChartDB.cpp
        hdr/AppEngine.h
        hdr/DBController/QMongoDB.h
        hdr/Model/Constants_Def.h
        hdr/View/Screen_Def.h
        hdr/Plugin/QCircleMeter.h
        hdr/Plugin/SensorsMQTT.h
        hdr/Plugin/QChartDB.h
        qml.qrc
)

include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(IoT-Dashboard
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(IoT-Dashboard SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(IoT-Dashboard
          ${PROJECT_SOURCES}
        )
    endif()
endif()

target_compile_definitions(IoT-Dashboard
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(IoT-Dashboard
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Mqtt ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES} nlohmann_json::nlohmann_json)
