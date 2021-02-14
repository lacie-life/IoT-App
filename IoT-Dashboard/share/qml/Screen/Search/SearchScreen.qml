import QtQuick 2.0
import "../../Component"
import "../../Component/Common"
import QmlCustomItem 1.0

QRec {
    id: root
    color: CONST.BACK_GROUND_COLOR

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

            text: CONST.IMAGE_FOLDER + "              " + inputBox.width
            QRec {
                anchors.fill: parent
                color: "red"
                opacity: 0.4
            }
        }
    }

}
