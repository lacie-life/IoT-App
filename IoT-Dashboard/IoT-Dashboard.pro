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
    $$HEADER_PATH/Model/AppModel.h

SOURCES += \
    $$SOURCE_PATH/AppEngine.cpp \
    $$SOURCE_PATH/Plugin/QCircleMeter.cpp \
#    $$SOURCE_PATH/Plugin/SensorsMQTT.cpp \
#    $$SOURCE_PATH/DBController/QMongoDB.cpp
    $$SOURCE_PATH/main.cpp \
    $$SOURCE_PATH/Plugin/QChart.cpp \
    $$SOURCE_PATH/Model/EasingFunction.cpp \
    $$SOURCE_PATH/Model/AppModel.cpp

RESOURCES +=

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CMakeLists.txt \
    share/qml/Component/Common/QImage.qml \
    share/qml/Component/Common/QRec.qml \
    share/qml/Component/Common/QText.qml \
    share/qml/Component/Common/QTimer.qml \
    share/qml/Component/QButton.qml \
    share/qml/Component/QChartRealTime.qml \
    share/qml/Component/QHorizontalSwipeButton.qml \
    share/qml/Component/QMenuBar.qml \
    share/qml/Component/QSensorClock.qml \
    share/qml/Component/QSwitchButton.qml \
    share/qml/MainScreen.qml \
    share/qml/Screen/Home/HomeScreen.qml \
    share/qml/Screen/Search/SearchScreen.qml \
    share/qml/TestScreen.qml \
    share/qml/main.qml \
    share/res/dark/control.svg \
    share/res/dark/home.svg \
    share/res/dark/map.svg \
    share/res/dark/search.svg \
    share/res/dark/user.svg \
    share/res/light/control.svg \
    share/res/light/home.svg \
    share/res/light/map.svg \
    share/res/light/search.svg \
    share/res/light/user.svg \
    share/script/release.sh

# COPY RESOURCES TO BUILD DIRECTORY
copydata.commands = $(COPY_DIR) $$PWD/share/ $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
