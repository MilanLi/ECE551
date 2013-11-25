import QtQuick 1.1

Item {
    id:aboutPanel
    width: parent.width/2
    height: parent.height*3/5
    anchors.centerIn: parent

    Frame {
        id: aboutPanelFrame
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        //state:"hide"

        Item{
            id:backButton
            width:gameLogo.height
            height:gameLogo.height
            anchors.margins: 10
            anchors.top: parent.top
            anchors.left:parent.left

            Image{
                source:"images/back.png"
                width:gameLogo.height
                height:gameLogo.height
                anchors.centerIn: parent
                smooth:true
            }
            MouseArea{
                anchors.fill: parent

                onClicked: {
                    aboutPanel.state = "hide"
                    //gameData.pauseGame(false)
                }

            }
        }

        Image {
            id: gameLogo
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            source: "images/logo.png"
            width:parent.width*3/5
            height:width*35/150;
            smooth:true
        }

        Frame {
            id: aboutArea
            anchors.horizontalCenter: parent.horizontalCenter
            width:parent.width-20
            height:parent.height-gameLogo.height-30
            anchors.margins: 10
            anchors.top: gameLogo.bottom
            gradient: Gradient {
                GradientStop { position: 0.0; color: "#ffffff" }
                GradientStop { position: 1.0; color: "#eeeeee" }
            }

            Flickable {
                id: aboutAreaFlickable
                anchors.fill: parent
                contentWidth: aboutArea.width
                contentHeight: aboutAreaText.height +aboutAreaLogo.height + 20
                flickableDirection: Flickable.VerticalFlick
                clip: true
                Text {
                    id: aboutAreaText
                    width: parent.width - 20
                    anchors.horizontalCenter: parent.horizontalCenter
                    wrapMode: Text.WordWrap
                    horizontalAlignment: Text.AlignHCenter
                    font.family: "Helvetica"
                    font.pointSize: parent.width/24+1
                    text: "\nThis game is the classical Reversi, also " +
                            "known as Othello. Players place their pieces" +
                            "pieces in turns, anywhere in the 8x8 size board" +
                            "as long as it can incur a flip. The winner is " +
                            "the player who has the more pieces at the end of"+
                            "the game.\n\nGame logic is implemented with Qt " +
                            "C++ and the UI with QML Declarative UI.\n\nEnjoy! =)\n"
                }
                AnimatedImage {
                    id: aboutAreaLogo
                    source: "images/6.gif"
                    width:parent.width-20
                    height:width
                    smooth:true
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: aboutAreaText.bottom
                    anchors.topMargin: 10

                }
            }
        }
    }
    states: [
        State {
            name: "hide"
            PropertyChanges {
                target: aboutPanel
                opacity: 0.0
                //y: -menuPanelFrame.height
            }
        }
    ]

    transitions: Transition {
        NumberAnimation {
            properties: "opacity, y"
            duration: 400
        }
    }

}
