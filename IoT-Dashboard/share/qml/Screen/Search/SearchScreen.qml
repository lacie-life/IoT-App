import QtQuick 2.0
import "../../Component"
import "../../Component/Common"
import QmlCustomItem 1.0

QRectangle {
    id: root
    color: CONST.BACK_GROUND_COLOR

    QRectangle {
        id: inputBox
        width: CONST.INPUT_BOX_WIDTH
        height: CONST.INPUT_BOX_HEIGHT
        anchors.horizontalCenter: root.horizontalCenter
        anchors.top: root.top
        anchors.topMargin: CONST.INPUT_BOX_TOP_MARGIN
        radius: 20

        TextInput {
            id: inputText
            width: CONST.INPUT_BOX_WIDTH - CONST.INPUT_BOX_HEIGHT - inputText.anchors.leftMargin
            height: CONST.INPUT_BOX_HEIGHT
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 10
            text: CONST.IMAGE_FOLDER
        }
    }

}
