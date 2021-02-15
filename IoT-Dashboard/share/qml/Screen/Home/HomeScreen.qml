import QtQuick 2.0
import "../../Component"
import "../../Component/Common"
import QmlCustomItem 1.0

QRec {
    id: root
    color: CONST.COLOR_BACK_GROUND

    QChartRealTime {
        id: chart
        width: 700
        height: 500

        anchors.verticalCenter: root.verticalCenter
        anchors.left: root.left
        anchors.leftMargin: 20

        xGrid: 12
        yGrid: 10
        lineColor: "blue"
        grid: ENUMS.YGrid
        easing: ENUMS.InOutSine
        dotSize: 4

        color: CONST.COLOR_BACK_GROUND
    }

    QSensorClock {
        id: clock
        width: 200
        height: width
        anchors.verticalCenter: root.verticalCenter
        anchors.right: root.right
        anchors.rightMargin: 100
        border: true

        bgColor: CONST.COLOR_BACK_GROUND
        ringSize: 35
    }

    Timer {
        id: timer
        interval: 1000
        triggeredOnStart: true
        repeat: true
        running: false
        onTriggered: {
            var data = 20//Math.random() * (100 - 0) + 0
            chart.addData(data)
            clock.updateData(data)
        }
    }

    Component.onCompleted: {
        timer.start()
    }
}
