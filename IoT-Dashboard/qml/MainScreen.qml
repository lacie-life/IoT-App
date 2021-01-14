import QtQuick 2.0
import "Component"

Item
{
    id: root
    property int sData: button.isActive ? 40 : 10

    QSensorClock
    {
        id: clock
        anchors.centerIn: parent
        dataUpdate: sData
        updateInterval: 2

        thickness: 30
    }

    QSwitchButton
    {
        id: button
        anchors
        {
            horizontalCenter: clock.horizontalCenter
            top: clock.bottom
            topMargin: 50
        }

        width: 50
        height: 25
    }

}
