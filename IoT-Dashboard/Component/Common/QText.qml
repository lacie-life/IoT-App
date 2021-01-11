import QtQuick 2.0

Text
{
    id: root
    property alias isBold: font.bold

    font.bold: false
    text: ""
}
