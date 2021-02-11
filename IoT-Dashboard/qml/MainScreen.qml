import QtQuick 2.0
import "Component"
import QmlCustomItem 1.0

Item
{
    id: root

    QChartRealTime
    {
        id: chart
        width: 400
        height: 350
        xGrid: 12
        yGrid: 10
        grid: ENUMS.Grid
        easing: ENUMS.InOutSine
    }

    Timer {
        id: timer
        interval: 1000
        triggeredOnStart: true
        repeat: true
        running: true
        onTriggered: {
            chart.addData(Math.random() * (100 - 0) + 0)
        }
    }

}
