import QtQuick 2.0
import "Common"

QButton
{
    id: root

    // properties edclare here
    property bool isActive: false
    property alias noodColor: noodID.color


    readonly property int noodSizeOffset: 10
    readonly property int noodPosLeft: noodSizeOffset / 2
    readonly property int noodPosRight: width - noodID.width - noodSizeOffset / 2


    // main
    width: 100
    height: 50
    radius: (height < width) ? (height / 2) : (width / 2)
    color: isActive ? CONST.SWITCH_ON_COLOR : CONST.SWITCH_OFF_COLOR

    QRectangle
    {
        id: noodID
        width: (root.width < root.height) ? (root.width - root.noodSizeOffset > 0 ? root.width - root.noodSizeOffset : 0)
                                          : (root.height - root.noodSizeOffset > 0 ? root.height - root.noodSizeOffset : 0)
        height: width
        radius: width / 2

        anchors
        {
            verticalCenter: root.verticalCenter
            left: root.left
            leftMargin: root.noodPosLeft
        }
        color: CONST.SWITCH_BTN_NOOD
    }

    PropertyAnimation
    {
        id: turnOn
        target: noodID
        properties: "anchors.leftMargin"
        from: root.noodPosLeft
        to: root.noodPosRight
        duration: 150
        running: false
        alwaysRunToEnd: true
        easing.type: Easing.OutQuad
    }

    PropertyAnimation
    {
        id: turnOff
        target: noodID
        properties: "anchors.leftMargin"
        from: root.noodPosRight
        to: root.noodPosLeft
        duration: 150
        running: false
        alwaysRunToEnd: true
        easing.type: Easing.OutQuad
    }

    onClicked:
    {
        if (isActive)
        {
            turnOff.start()
        }
        else
        {
            turnOn.start()
        }

        isActive = !isActive
    }
}
