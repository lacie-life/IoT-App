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

    QRec {
        id: mainScreen
        width: root.width - CONST.MENU_BAR_WIDTH
        height: root.height
        anchors.top: root.top
        anchors.left: menuBar.right

        color: CONST.COLOR_INVISIBLE
    }

    Loader {
        id: searchLoader
        visible: AppModel.currentScreenID === ENUMS.SearchScreen
        anchors.fill: mainScreen
        source: SCREEN.QML_SEARCH
    }

    Loader {
        id: homeLoader
        visible: AppModel.currentScreenID === ENUMS.HomeScreen
        anchors.fill: mainScreen
        source: SCREEN.QML_HOME
    }

}
