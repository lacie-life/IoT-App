import QtQuick 2.4

Rectangle {
    id: text
    width: 320
    height: 480
    color: "lightgray"

    Text {
            id: helloText
            text: "Hello world!"
            y: 30
            anchors.horizontalCenter: page.horizontalCenter
            font.pointSize: 24; font.bold: true
        }
}
