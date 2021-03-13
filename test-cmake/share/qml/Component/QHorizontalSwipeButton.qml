import QtQuick 2.0
import "../Component"
import "../Component/Common"

QButton {
    id: root

    // property
    readonly property bool leftState : false
    readonly property bool rightState: true

    property bool state: leftState
    property bool switching: false

    property int maxTextWidth: width/2 - 20
    property alias leftText: txtLeft.text
    property alias rightText: txtRight.text

    // function and slot
    onClicked: {
        state = !state
    }

    // main component
    clip: true

    // left
    QRec {
        id: leftSide
        anchors.left: root.left

        width: root.width / 2 + 10
        height: root.height
        z: -2
        radius: root.radius
        color: CONST.COLOR_SWITCH_ON
        visible: !root.switching && root.state === root.leftState && false
    }

    QText {
        id: txtLeft
        anchors.centerIn: leftSide
        z: 2
        text: CONST.EMPTY_STRING + root.state
        color: "black"
    }

    // right
    QRec {
        id: rightSide
        anchors.right: root.right
        width: leftSide.width
        height: leftSide.height
        z: -2
        radius: 20
        color: CONST.COLOR_SWITCH_ON
        visible: !root.switching && root.state === root.rightState && false
    }

    QText {
        id: txtRight
        anchors.centerIn: rightSide
        z: 2
        text: CONST.EMPTY_STRING + root.state
        color: "black"
    }

    // switch
    QRec {
        id: switchNood
        visible: root.switching || true
        anchors.verticalCenter: root.verticalCenter
        anchors.left: root.left
        anchors.leftMargin: root.state === root.leftState ? 0 : root.width - switchNood.width
        width: leftSide.width
        height: leftSide.height
        radius: 20
        z: -1
        color: CONST.COLOR_SWITCH_ON

        Behavior on anchors.leftMargin {
            NumberAnimation {
                duration: 150
                alwaysRunToEnd: true
                onStopped: {
                    console.log("end")
                }
            }
        }
    }

    border.color: CONST.COLOR_BORDER_DARK
    border.width: 1
}
