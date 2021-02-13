import QtQuick 2.0
import "Component"
import "Component/Common"
import QmlCustomItem 1.0

Item
{
    id: root

    QMenuBar {
        id: menuBar
        width: CONST.MENU_BAR_WIDTH
        height: root.height
        anchors.left: root.left
        anchors.top: root.top
    }

    Loader {
        id: funcScreen
        width: root.width - CONST.MENU_BAR_WIDTH
        height: root.height
        anchors.top: root.top
        anchors.left: menuBar.right

        source: "qrc:/qml/Screen/HomeScreen.qml"
    }

}
