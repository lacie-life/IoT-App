import QtQuick 2.0

Image
{
    id: root
    property alias backgroundColor: bg.color

    QRectangle
    {
        id: bg
        anchors.fill: parent
        color: "transparent"
    }

    source: ""

}

