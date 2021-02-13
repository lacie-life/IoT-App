import QtQuick 2.0
import "../Component"
import "../Component/Common"
import QmlCustomItem 1.0

QRectangle {
    id: root
    color: CONST.BACK_GROUND_COLOR

    QChartRealTime
    {
        id: chart
        width: 700
        height: 500

        anchors.verticalCenter: root.verticalCenter
        anchors.left: root.left
        anchors.leftMargin: 20

        xGrid: 12
        yGrid: 10
        lineColor: "blue"
        grid: ENUMS.Grid
        easing: ENUMS.InOutSine
        dotSize: 4

        color: CONST.BACK_GROUND_COLOR
    }

    QSensorClock {
        id: clock
        width: 200
        height: width
        anchors.verticalCenter: root.verticalCenter
        anchors.right: root.right
        anchors.rightMargin: 100
        border: true

        bgColor: CONST.BACK_GROUND_COLOR
        ringSize: 35
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
