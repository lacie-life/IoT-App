import QtQuick 2.0
import QmlCustomItem 1.0
import "Common"

Item
{
    id: root

    property int textSize: 25
    property bool textBold: false
    property string textColor: "#000000"
    property bool textVisible: true

    property alias unfilledColor    : chartID.unfilledColor
    property alias filledColor      : chartID.fillColor
    property alias staticBarColor   : chartID.bottomColor
    property alias bgColor          : chartID.centerColor
    property alias border           : chartID.border
    property alias borderColor      : chartID.borderColor

    property alias ringSize         : chartID.thickness

    width: 200
    height: 200

    QCircleMeter
    {
        id: chartID

        property int diffData: 0

        width: root.width
        height: root.height
        anchors.centerIn: parent

        data: 0
        Behavior on data {
            // duration is scaled from 100ms to 300ms
            NumberAnimation {
                duration: chartID.diffData <  0  ?   0 :
                          chartID.diffData <= 10 ? 150 :
                          chartID.diffData <= 20 ? 200 :
                          chartID.diffData <= 40 ? 250 :
                          chartID.diffData <= 80 ? 300 :
                          350
                easing.type: Easing.OutQuad
                alwaysRunToEnd: true
                onStopped: {
                    chartID.diffData = 0
                }
            }
        }
    }

    QText {
        id: text
        visible: root.textVisible

        anchors.centerIn: chartID
        text: (chartID.data > 9 ? qsTr("%1%") : qsTr(" %1%")).arg(chartID.data)
        fontSize: root.textSize
        isBold: root.textBold
        color: root.textColor
    }

    QTimer {
        id: updateDataTimer
        interval: root.updateInterval * 1000
        repeat: true
        onTriggered: {
            if (root.dataUpdate !== chartID.data) {
                chartID.diffData = Math.abs(root.dataUpdate - chartID.data)
                chartID.data = root.dataUpdate
            }
        }
    }

    function updateData(newData) {
        chartID.diffData = Math.abs(newData - chartID.data)
        chartID.data = newData
    }

}
