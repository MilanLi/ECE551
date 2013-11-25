import QtQuick 1.1

Item {
    id:demoPanel1
    width: parent.width/2
    height: parent.height*3/5
    anchors.centerIn: parent

    property int level:-1

    Frame {
        id: demoPanelFrame
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
            /*enabled: {
                if(gameData.gameOn)
                    true
                else
                    false
            }
            opacity:{
                if(gameData.gameOn)
                    1.0
                else
                    0.3
            }*/

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
                    menuPanel.state = ""
                    demoPanel1.state = "hide"
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

        Text {
            id: computer1Text
            anchors.margins: 5
            height: parent.height/18
            text: "Select level for computer 1"
            font.family: "Helvetica"
            font.pointSize: height*0.7
            color: "#ffffff"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: gameLogo.bottom

        }

        Column {
            width: parent.width-10;//- aboutArea.width - 10
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.top: computer1Text.bottom
            anchors.margins: 10
            spacing: height/30

            Button {
                id: easyGame
                height:parent.height/6
                Text {
                    text: "Easy Game"
                    font.family: "Helvetica"
                    font.pointSize: parent.height/4+1
                    color:"#ffffff"
                    anchors.centerIn: parent
                    //disabled: true
                }


                onClicked: {
                    //gameData.resetGame()
                    //gameView.centerBoard()
                    demoPanel1.state = "hide"
                    demoPanel2.state = ""
                    //gameData.pauseGame(false)
                    level = 1
                    // TODO: Implement 1 player game
                }
            }

            Button {
                id: normalGame
                height:parent.height/6
                Text {
                    text: "Normal Game"
                    font.family: "Helvetica"
                    font.pointSize: parent.height/4+1
                    color:"#ffffff"
                    anchors.centerIn: parent
                    //disabled: true
                }
                onClicked: {
                    //gameData.resetGame()
                    //gameView.centerBoard()
                    demoPanel1.state = "hide"
                    demoPanel2.state = ""
                    //gameData.pauseGame(false)
                    level = 2
                }
            }

            Button {
                id: mediumGame
                height:parent.height/6
                Text {
                    text: "Medium Game"
                    font.family: "Helvetica"
                    font.pointSize: parent.height/4+1
                    color:"#ffffff"
                    anchors.centerIn: parent
                    //disabled: true
                }
                onClicked: {
                    //gameData.resetGame()
                    //gameView.centerBoard()
                    demoPanel1.state = "hide"
                    demoPanel2.state = ""
                    //gameData.pauseGame(false)
                    level = 3
                }
            }

            Button {
                id: hardGame
                height:parent.height/6
                Text {
                    text: "Hard Game"
                    font.family: "Helvetica"
                    font.pointSize: parent.height/4+1
                    color:"#ffffff"
                    anchors.centerIn: parent
                    //disabled: true
                }
                onClicked: {
                    //gameData.resetGame()
                    //gameView.centerBoard()
                    demoPanel1.state = "hide"
                    demoPanel2.state = ""
                    //gameData.pauseGame(false)
                    level = 4
                }
            }

            Button{
                id:exit
                height:parent.height/6
                Text {
                    text: "Exit"
                    font.family: "Helvetica"
                    font.pointSize: parent.height/4+1
                    color:"#ffffff"
                    anchors.centerIn: parent
                    //disabled: true

                }
                onClicked: {
                    mainWidget.exitApplication()
                }
            }
        }
    }
    states: [
        State {
            name: "hide"
            PropertyChanges {
                target: demoPanel1
                opacity: 0.0
                //y: -menuPanelFrame.height
            }
        }
    ]

    transitions: Transition {
        NumberAnimation {
            properties: "opacity, y"
            duration: 0
        }
    }
}
