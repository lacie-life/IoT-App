import QtQuick 2.0
import "Common"
import QmlCustomItem 1.0

QRectangle {
    id: root
    color: CONST.MENU_BAR_COLOR
    width: 80
    height: 680

    ListView {
        id: listScreen
        model: 5
        width: root.width
        height: root.height
        currentIndex: 0
        interactive: contentHeight > height

        delegate: Item {
            id: delegateItem
            width: parent.width
            height: width

            QButton {
                id: icon

                allowImage: true
                anchors.fill: parent

                sizeImage: width * 50 / 100
                sourceImage: getIcon(index, listScreen.currentIndex === index)
                onClicked: listScreen.currentIndex = index
                color: listScreen.currentIndex === index ? CONST.MENU_BAR_FOCUS_COLOR : CONST.INVISIBLE
            }
        }
    }

    function getIcon(index, isDark) {
        var colorFolder = "light/"
        if (isDark) {
            colorFolder = "dark/"
        }

        switch(index) {
        case 0:
            return CONST.IMAGE_FOLDER + colorFolder + CONST.SEARCH_IMG
        case 1:
            return CONST.IMAGE_FOLDER + colorFolder + CONST.HOME_IMG
        case 2:
            return CONST.IMAGE_FOLDER + colorFolder + CONST.CONTROL_IMG
        case 3:
            return CONST.IMAGE_FOLDER + colorFolder + CONST.MAP_IMG
        case 4:
            return CONST.IMAGE_FOLDER + colorFolder + CONST.USER_IMG
        default:
            return ""
        }
    }
}
