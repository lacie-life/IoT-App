import QtQuick 2.4

Item {
    id: container
    property alias cellColor: rectangle.color

    signal clicked() // khi thang con clicked, thi no ban ra cai signal nay
    // r o ben ngoai m onSingal la ok
    // qml thuong chi connect kieu nay thoi
    // the la ve co ban k nen dung signal qml de call slot c++?
    // deo
    // signal qml dung de ban cho thang cha no
    // signal c++ thuong connect voi slot c++ khac
    // doi khi no connect len qml
    // vi du nhu nay


    //thay ko
    // dau tien qml goi 1 ham cpp
    // ham do chay roi ban ra signal\
    // qml lai bat duoc signal day
    // va in ra
    // hmm hmm
    // the co bao h cpp call slot qml k
    // duoc
    // thoai mai
    // nhung deo ai lam vay
    // m co the tim hieu qua
    // hieu den dau thi hieu

    // tim kieu do
    // nhung dit me deo ai lma vay
    // cai cai code cua du an
    // may tram k dong
    // t van chua thay ai dung cach ngu xuan vay
    // neu da muon xu ly logic thi lam me duoi cpp
    // mang len qml lam gi
    // cai nay tao ra chi de cho co
    // tren qml lai vet bang js nua
    // noi chug la deo thi tot  hon
    // ok. de t xem lai
    // di ngu di mai nghie cuu tiep
    // deo
    // mai  t di an tat nien cung anh em
    // chac lai den dem
    // ngay kia neu m muon
    // nhung ngay kia t len cty
    // chu nhat neu m muon
    // hoac o cty thi m co the inbox skype
    // va khong dung team view dc
    // de xem

    width: 40; height: 25

    Rectangle {
        id: rectangle
        border.color: "white"
        anchors.fill: parent
    }

     MouseArea {
        anchors.fill: parent
        onClicked: container.clicked() // the la du hieu r
     }
}
