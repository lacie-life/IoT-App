import QtQuick 2.0
import "Common"

Item
{
    objectName: "MyChild"
    // vi du cai signal nay
    // thi nhu nay no van lam doi mau hello world ay
    // dung r, m co thay ko
    // cai onClicked la dac san cua MouseArea
    // nhung m khong co cai MouseArea nao o doui m van goi duoc

    // cai signal tren qml hay dung de ban tu thang con ra, va thangcha nhan no

    signal testQml(string data)


    Connections
    {
        target: MyColor
        onSendColorToQml:
        {
            console.log("Day la QML: "+ color)
        }
    }



    Rectangle {
        id: page
        width: 320; height: 480
        color: "lightgray"

        Text {
            id: helloText
            text: "Hello world!"
            y: 30
            anchors.horizontalCenter: page.horizontalCenter
            font.pointSize: 24; font.bold: true
        }

        Grid {
            id: colorPicker
            x: 4; anchors.bottom: page.bottom; anchors.bottomMargin: 4
            rows: 2; columns: 3; spacing: 3

            // dit me dung tiet kiem dong
            QCell
            {
                cellColor: "red"
                onClicked:
                {
                    MyColor.testFunctionCpp(cellColor)
                    helloText.color = cellColor
                }
            }
            QCell
            {
                cellColor: "green"
                onClicked:
                {
                    MyColor.testFunctionCpp(cellColor)
                    helloText.color = cellColor
                }
            }
            QCell
            {
                cellColor: "blue"
                onClicked:
                {
                    MyColor.testFunctionCpp(cellColor)
                    helloText.color = cellColor
                }
            }
            QCell
            {
                cellColor: "yellow"
                onClicked:
                {
                    MyColor.testFunctionCpp(cellColor)
                    helloText.color = cellColor
                }
            }
            QCell
            {
                cellColor: "gray"
                onClicked:
                {
                    MyColor.testFunctionCpp(cellColor)
                    helloText.color = cellColor
                }
            }
            // find child deo on, vi co tan 6 cai cung ten
            // cho nen m chi co the lay cai dau tien no tim thay
            // luc nay thi co cac h khac la tao 1 signal o thang to, roi on click thi ban signal tai thang to thoi
            // like this
        }
    }
}
