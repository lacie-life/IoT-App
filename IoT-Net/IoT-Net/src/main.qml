import QtQuick 2.3
import QtQuick.Window 2.2

// main window
Window {	
    visible: true
    width: 640
    height: 480

    //thuc ra deo can vi cai mainscreen co 1 cai duy nhat
    Loader
    {
        anchors.fill: parent
        source: "qrc:/MainScreen.qml"
    }
}


