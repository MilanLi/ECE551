import QtQuick 1.1

Item {
    id: menuPanel
    width: parent.width/2
    height: parent.height*3/5
    anchors.centerIn: parent

    //property bool fluid3D: switch3D.on
    property int mode:-1



    Frame {
        id: menuPanelFrame
        width: parent.width
        height: parent.height
        anchors.centerIn: parent

        Item{
            id:backButton
            width:gameLogo.height
            height:gameLogo.height
            anchors.margins: 10
            anchors.top: parent.top
            anchors.left:parent.left
            enabled: {
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
            }

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
                    menuPanel.state = "hide"
                    levelPanel.state = "hide"
                    gameData.pauseGame(false)
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

        Column {
            width: parent.width-10;//- aboutArea.width - 10
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.top: gameLogo.bottom
            anchors.margins: 10
            spacing: parent.height/30


            Button {
                id: button1PlayerGame
                height:parent.height/6
                Text {
                    text: "1 Player Game"
                    font.family: "Helvetica"
                    font.pointSize: parent.height/4+1
                    color:"#ffffff"
                    anchors.centerIn: parent
                    //disabled: true
                }


                onClicked: {
                    mode = 1
                    levelPanel.state = ""
                    menuPanel.state = "hide"
                    // TODO: Implement 1 player game
                }
            }
            Button {
                id: button2PlayerGame
                height:parent.height/6
                Text {
                    text: "2 Players Game"
                    font.family: "Helvetica"
                    font.pointSize: parent.height/4+1
                    color:"#ffffff"
                    anchors.centerIn: parent
                    //disabled: true
                }
                onClicked: {
                    mode = 2
                    gameData.resetGame()
                    //gameView.centerBoard()
                    menuPanel.state = "hide"
                    levelPanel.state = "hide"
                    gameData.pauseGame(false)

                }
            }

            Button{
                id:buttonDemoGame
                height:parent.height/6
                Text {
                    text: "Computer Demo"
                    font.family: "Helvetica"
                    font.pointSize: parent.height/4+1
                    color:"#ffffff"
                    anchors.centerIn: parent
                    //disabled: true
                }
                onClicked:{
                    demoPanel1.state = ""
                    menuPanel.state = "hide"
                    mode = 3
                }
            }

            Button{
                id:buttonAbout
                height:parent.height/6
                Text {
                    text: "About Game"
                    font.family: "Helvetica"
                    font.pointSize: parent.height/4+1
                    color:"#ffffff"
                    anchors.centerIn: parent
                    //disabled: true
                }
                onClicked: {
                    aboutPanel.state=""
                    levelPanel.state = "hide"

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

            /*Button {
                    id: buttonContinue
                    text: "Continue Game"
                    // "Continue" button is enabled only when game is on
                    disabled: {
                        if (!gameData.gameOn)
                            return true
                        else
                            return false
                    }
                    onClicked: {
                        menuPanel.state = "hide"
                        gameData.pauseGame(false)
                    }
                }*/
        }
    }
    //}

    states: [
        State {
            name: "hide"
            PropertyChanges {
                target: menuPanel
                opacity: 0.0
                //y: -menuPanelFrame.height
            }
        }
    ]

    transitions: Transition {
        NumberAnimation {
            properties: "opacity"
            duration: 0
        }
    }

}
