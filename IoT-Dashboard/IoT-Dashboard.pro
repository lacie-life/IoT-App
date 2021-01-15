QT += quick

CONFIG += c++11

HEADER_PATH = ./hdr
SOURCE_PATH = ./src

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    $$HEADER_PATH \
    $$HEADER_PATH/Model \
    $$HEADER_PATH/Plugin

HEADERS += \
    $$HEADER_PATH/AppEngine.h \
    $$HEADER_PATH/Model/Constants_Def.h \
    $$HEADER_PATH/Plugin/QCircleMeter.h \
    $$HEADER_PATH/Plugin/SensorsMQTT.h

SOURCES += \
        $$SOURCE_PATH/AppEngine.cpp \
        $$SOURCE_PATH/Model/Constants_Def.cpp \
        $$SOURCE_PATH/Plugin/QCircleMeter.cpp \
        $$SOURCE_PATH/Plugin/SensorsMQTT.cpp \
        $$SOURCE_PATH/main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CMakeLists.txt
