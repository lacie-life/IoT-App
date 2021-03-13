import QtQuick 2.0
import "../../Component"
import "../../Component/Common"
import QmlCustomItem 1.0

QRec {
    id: homeScreen
    color: CONST.COLOR_BACK_GROUND

    QHorizontalSwipeButton {
        id: swipeTab
        width: 400
        height: 50
        radius: 20
        anchors.centerIn: parent

    }
}
