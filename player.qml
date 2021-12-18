import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 260
    height: 100
    visible: true
    title: qsTr("Player")
    property double stepPlay: 0;


    Timer{
        id: timer
        interval: 1000; running: true; repeat: true
        onTriggered: playProgress.value += stepPlay;
    }
    
    ProgressBar{
        id: playProgress
        width: parent.width
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button{
        id: play
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: -105
        width: 50
        height: 30
        text:"▶️"
        onClicked: {
            stepPlay = 0.05
            timer.start()
        }
    }

    Button{
        id: pause
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: -53
        width: 50
        height: 30
        text:"⏸️"
        onClicked: {
           timer.stop()
        }
    }

    Button{
        id: stop
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: -1
        width: 50
        height: 30
        text:"⏹"
        onClicked: {
            timer.stop()
            playProgress.value = 0
        }
    }

    Button{
        id: rewind
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: 51
        width: 50
        height: 30
        text:"⏪️"
        onClicked: {
            stepPlay = -0.15
            timer.start()
        }
    }

    Button{
        id: forward
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: 103
        width: 50
        height: 30
        text:"⏩️"
        onClicked: {
            stepPlay = 0.15
            timer.start()
        }
    }

}
