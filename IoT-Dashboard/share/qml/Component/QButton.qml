import QtQuick 2.0
import "Common"

QRec
{
    id: root
    // properties
    property string sourceImage: ""
    property string label: ""
    property bool allowHover: false
    property bool allowText: false
    property bool allowImage: false
    property int sizeImage: width

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
    color: CONST.COLOR_INVISIBLE

    QImage
    {
        id: imageID
        width: root.sizeImage
        height: width
        anchors.centerIn: root
        imgName: root.sourceImage
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
