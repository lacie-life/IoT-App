import QtQuick 2.0
import "../../Component"
import "../../Component/Common"
import QmlCustomItem 1.0

QRec {
    id: root
    color: CONST.COLOR_BACK_GROUND

    QRec {
        id: inputBox
        width: CONST.INPUT_BOX_WIDTH
        height: CONST.INPUT_BOX_HEIGHT
        anchors.horizontalCenter: root.horizontalCenter
        anchors.top: root.top
        anchors.topMargin: CONST.INPUT_BOX_TOP_MARGIN
        radius: 20
        clip: true

        TextInput {
            id: inputText
            clip: true

            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 20

            width: parent.width - CONST.INPUT_BOX_HEIGHT - inputText.anchors.leftMargin
            height: CONST.INPUT_BOX_HEIGHT

            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter

            text: ""

            onTextChanged: {
//                console.log(text)
            }
        }
    }

    QRec {
        id: searchList
        width: root.width
        height: root.height - inputBox.height - searchList.anchors.topMargin

        anchors.top: inputBox.bottom
        anchors.topMargin: inputBox.anchors.topMargin
        anchors.left: root.left

        color: CONST.COLOR_INVISIBLE
    }

}
