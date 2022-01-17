import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Ball in Box")

    Rectangle {
        id: scene
        anchors.fill: parent
        state: "initState"

        Rectangle {
        id: leftRect
        width: 100
        height: 100
        x: 100
        y: 100
        color: "grey"
        border.color: "black"

        Text {
            id: lName
            anchors.centerIn: leftRect
            text: "move"
            color: "black"
        }

        MouseArea {
            id: leftRectArea
            anchors.fill: parent
            onClicked: {
                if(ball.x >= rightRect.x){
                    scene.state = "initState";
                }
                else{
                    ball.x += 50
                    scene.state = "changeState"
                }
            }
        }
    }

        Rectangle {
        id: rightRect
        width: leftRect.width
        height: leftRect.height
        x: leftRect.x + 400
        y: leftRect.y
        color: "grey"
        border.color: "black"

        Text {
            id: rName
            anchors.centerIn: rightRect
            text: "return"
            color: "black"
        }

        MouseArea {
            id: rightRectArea
            anchors.fill: parent
            onClicked: {
                scene.state = "initState"
            }
        }
    }

        Rectangle {
        id: ball
        width: leftRect.width - 10
        height: leftRect.height - 10
        y: leftRect.y + 5
        radius: width / 2
        color: "blue"

        Text {
            anchors.centerIn: ball
            text: "Sharik"
        }
    }

        states: [
            State {
                name: "initState"
                PropertyChanges {
                    target: ball
                    x: leftRect.x + 5
                }
            },

            State {
                name: "changeState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            }
        ]

        transitions: [
           Transition {
                from: "changeState"
                to: "initState"

                NumberAnimation {
                    properties: "x,y"
                    duration: 1000
                    easing.type: Easing.OutBounce
                }
            }
        ]
    }
}
