import QtQuick 2.0
import "Component"
import "Component/Common"
import QmlCustomItem 1.0

Item
{
    id: root

    QRectangle {
        id: bg
        anchors.fill: parent
        color: "#aaaaaa"
    }

    QChartRealTime
    {
        id: chart
        width: 400
        height: 350

        anchors.verticalCenter: root.verticalCenter
        anchors.left: root.left

        xGrid: 12
        yGrid: 10
        lineColor: "blue"
        grid: ENUMS.Grid
        easing: ENUMS.InOutSine
        dotSize: 4

        color: "#aaaaaa"
    }

    QSensorClock {
        id: clock
        width: 200
        height: width
        anchors.verticalCenter: root.verticalCenter
        anchors.right: root.right
        anchors.rightMargin: 25

        bgColor: "#aaaaaa"
    }

    Timer {
        id: timer
        interval: 1000
        triggeredOnStart: true
        repeat: true
        running: false
        onTriggered: {
            var data = Math.random() * (100 - 0) + 0
            chart.addData(data)
            clock.updateData(data)
        }
    }

    Component.onCompleted: {
        timer.start()
    }

}
