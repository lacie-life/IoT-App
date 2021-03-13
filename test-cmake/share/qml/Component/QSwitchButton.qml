import QtQuick 2.0
import "Common"

QButton
{
    id: root

    // properties edclare here
    property bool isActive: false
    property bool isEnable: true
    property alias noodColor: noodID.color


    readonly property int noodSizeOffset: 10
    readonly property int noodPosLeft: noodSizeOffset / 2
    readonly property int noodPosRight: width - noodID.width - noodSizeOffset / 2
    readonly property int switchTime: 150

    // main
    width: 100
    height: 50
    radius: (height < width) ? (height / 2) : (width / 2)
    color: isActive ? CONST.COLOR_SWITCH_ON : CONST.COLOR_SWITCH_OFF

    QRec
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
        color: CONST.COLOR_SWITCH_BTN_NOOD
    }

    PropertyAnimation
    {
        id: turnOn
        target: noodID
        properties: "anchors.leftMargin"
        from: root.noodPosLeft
        to: root.noodPosRight
        duration: root.switchTime
        running: false
        alwaysRunToEnd: true
        easing.type: Easing.OutQuad

        onStarted:
        {
            isEnable = false
            reEnableTimer.start()
        }

        onStopped:
        {
            isActive = true;
        }
    }

    PropertyAnimation
    {
        id: turnOff
        target: noodID
        properties: "anchors.leftMargin"
        from: root.noodPosRight
        to: root.noodPosLeft
        duration: root.switchTime
        running: false
        alwaysRunToEnd: true
        easing.type: Easing.OutQuad

        onStarted:
        {
            isEnable = false
            reEnableTimer.start()
        }

        onStopped:
        {
            isActive = false
        }
    }

    onClicked:
    {
        if (isEnable)
        {
            if (isActive)
            {
                turnOff.start()
            }
            else
            {
                turnOn.start()
            }
        }
    }

    QTimer
    {
        id: reEnableTimer
        interval: root.switchTime
        onTriggered:
        {
            isEnable = true
        }
    }
}
