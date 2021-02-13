import QtQuick 2.0
import "Common"

QRectangle
{
    id: root
    // properties
    property string sourceImage: ""
    property string label: ""
    property bool allowHover: false
    property bool allowText: false
    property bool allowImage: false
    property int sizeImage: 0

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
    color: CONST.INVISIBLE

    QImage
    {
        id: imageID
        width: root.sizeImage
        height: width
        anchors.centerIn: root
        source: root.sourceImage
        visible: (root.sourceImage !== "" && allowImage)
    }

    QText
    {
        id: textID
        anchors.centerIn: parent
        text: root.label
        visible: (root.label !== "" && allowText)
    }

    MouseArea
    {
        anchors.fill: parent
        hoverEnabled: root.allowHover
        onClicked: root.clicked()
        onPressed: root.pressed()
        onPressAndHold: root.pressAndHold()
        onReleased: root.release()
        onEntered: root.hoveredIn()
        onExited: root.hoveredOut()
    }
}
