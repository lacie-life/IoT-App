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
    $$HEADER_PATH/Plugin \
    $$HEADER_PATH/DBController \
    $$HEADER_PATH/View

HEADERS += \
    $$HEADER_PATH/AppEngine.h \
    $$HEADER_PATH/Model/Constants_Def.h \
    $$HEADER_PATH/Plugin/QCircleMeter.h \
#    $$HEADER_PATH/Plugin/SensorsMQTT.h \
#    $$HEADER_PATH/DBController/QMongoDB.h
    $$HEADER_PATH/Plugin/QChart.h \
    $$HEADER_PATH/Model/EasingFunction.h \
    $$HEADER_PATH/Model/AppEnums.h \
    $$HEADER_PATH/View/Screen_Def.h \
    hdr/Model/AppModel.h

SOURCES += \
    $$SOURCE_PATH/AppEngine.cpp \
    $$SOURCE_PATH/Plugin/QCircleMeter.cpp \
#    $$SOURCE_PATH/Plugin/SensorsMQTT.cpp \
#    $$SOURCE_PATH/DBController/QMongoDB.cpp
    $$SOURCE_PATH/main.cpp \
    $$SOURCE_PATH/Plugin/QChart.cpp \
    $$SOURCE_PATH/Model/EasingFunction.cpp \
    src/Model/AppModel.cpp

RESOURCES += qml.qrc \
    images.qrc

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
