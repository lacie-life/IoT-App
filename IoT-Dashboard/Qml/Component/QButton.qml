import QtQuick 2.0
import "Common"

QRectangle
{
    id: root
    // properties
    property string sourceImage: ""
    property string label: ""
    property bool allowHover: true

    // signals declare

    signal clicked()
    signal pressed()
    signal release()
    signal pressAndHold()
    signal hoveredIn()
    signal hoveredOut()

    // main
    width: 100
    height: 100
    color: "transparent"

    QImage
    {
        id: imageID
        anchors.fill: parent
        source: sourceImage
        visible: sourceImage !== "" ? true : false
    }

    QText
    {
        id: textID
        anchors.centerIn: parent
        text: label
        visible: label !== "" ? true : false
    }

    MouseArea
    {
        anchors.fill: parent
        hoverEnabled: allowHover
        onClicked: clicked()
        onPressed: pressed()
        onPressAndHold: pressAndHold()
        onReleased: released()
        onEntered: hoveredIn()
        onExited: hoveredOut()
    }
}
