import QtQuick 2.0

Rectangle
{
    id: root
    property bool isActive: false
    property string noodColor: "#ffffff"
    property int noodSizeReduce: 10

    signal selectButtonClick()

    width: 100
    height: 50
    radius: height / 2

    color: isActive ? "#66ffb2" : "#a0a0a0"
    antialiasing: true

    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            selectButtonClick()
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

    Rectangle
    {
        id: nood
        width: (root.height - root.noodSizeReduce > 0) ? (root.height - root.noodSizeReduce) : 0
        height: width
        radius: width / 2
        color: root.noodColor

        anchors
        {
            verticalCenter: root.verticalCenter
            left: root.left
            leftMargin: noodSizeReduce / 2
        }

        PropertyAnimation
        {
            id: turnOn
            target: nood
            running: false
            properties: "anchors.leftMargin"
            from: noodSizeReduce / 2
            to: root.width - nood.width - noodSizeReduce / 2
            duration: 500
            alwaysRunToEnd: true

            onStopped:
            {
                nood.anchors.leftMargin = root.width - nood.width - noodSizeReduce / 2
            }
        }

        PropertyAnimation
        {
            id: turnOff
            target: nood
            running: false
            properties: "anchors.leftMargin"
            from: root.width - nood.width - noodSizeReduce / 2
            to: noodSizeReduce / 2
            duration: 500
            alwaysRunToEnd: true
            onStopped:
            {
                nood.anchors.leftMargin = noodSizeReduce / 2
            }
        }
    }
}
