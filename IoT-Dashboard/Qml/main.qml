import QtQuick 2.12
import QtQuick.Window 2.12

Window
{
    width: CONST.MAX_WIDTH
    height: CONST.MAX_HEIGHT
    visible: true

    Loader
    {
        anchors.fill: parent
        source: "qrc:/Qml/MainScreen.qml"
    }
}
