import QtQuick 2.0
import QmlCustomItem 1.0
import "Common"

QRec {
    id: root

    property alias xTitle   :       chartID.xAxis
    property alias yTitle   :       chartID.yAxis

    property alias axisSize :       chartID.axisThickness
    property alias dotSize  :       chartID.dotThickness
    property alias lineSize :       chartID.lineThickness

    property alias xGrid    :       chartID.xAxisDiv
    property alias yGrid    :       chartID.yAxisDiv
    property alias grid     :       chartID.gridMode

    property alias bgColor  :       chartID.backgroundColor
    property alias axisColor:       chartID.axisColor
    property alias lineColor:       chartID.lineColor
    property alias dotColor :       chartID.dotColor

    property alias xMaxVal  :       chartID.xMax
    property alias xMinVal  :       chartID.xMin
    property alias yMaxVal  :       chartID.yMax
    property alias yMinVal  :       chartID.yMin

    property alias easing   :       chartID.easingType

    QChart {
        id: chartID
        visible: root.width !== 0 && root.height !== 0
        anchors.fill: parent
        anchors.margins: 50
        gridMode: ENUMS.Grid
    }

    QText {
        id: xAxisTitle
        anchors.top: chartID.bottom
        anchors.topMargin: 5
        anchors.left: chartID.right
        anchors.leftMargin: 5
        fontSize: root.height / 25
        color: "black"
        text: chartID.xAxis
        visible: chartID.xAxis !== ""
    }

    QText {
        id: yAxisTitle
        anchors.bottom: chartID.top
        anchors.bottomMargin: 5
        anchors.right: chartID.left
        anchors.rightMargin: 5
        fontSize: root.height / 25
        color: "black"
        text: chartID.yAxis
        visible: chartID.yAxis !== ""
    }

    function addData(data) {
        chartID.appendData(data)
    }
}
