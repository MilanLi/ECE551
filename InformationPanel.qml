import QtQuick 1.1

Item {
    id:informationPanel
    Image{
        source: "images/frame.png"
        width:parent.width*2/5
        height:parent.height
        anchors.left: parent.left
        smooth:true

        Frame{
            id:player1
            anchors.centerIn: parent
            height:parent.height-10
            width:parent.width-10

            Text{
                text:"Player1"
                font.family: "Helvetica"
                font.pointSize: parent.height/3+1
                color:"#ffffff"
                anchors.verticalCenter: parent.verticalCenter
                //anchors.horizontalCenter: parent.horizontalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }
            Image{
                source:"images/tile_button1.png"
                width:parent.height
                height: parent.height
                smooth:true
                //anchors.horizontalCenter: parent.horizontalCenter
                anchors.left: parent.left
                opacity:{
                    if(gameData.player1Turn)
                        1.0
                    else
                        0.3
                }
            }
            Text{
                text:gameData.countBlack
                font.family: "Helvetica"
                font.pointSize: parent.height/3+1
                color:"#ffffff"
                anchors.centerIn: parent
            }
        }

    }
    Image{
        source: "images/frame.png"
        width:parent.width*0.15
        height:parent.height
        anchors.centerIn: parent
        smooth:true

        Text{
            id:moves
            text:"Moves: "+gameData.moves
            font.pointSize: parent.height/4+1
            anchors.margins: 5
        }

        Text{
            id:times
            anchors.top: moves.bottom
            text:"Time: "+gameData.gameTime
            font.pointSize: parent.height/4+1
            anchors.margins: 5
        }
    }

    Image{
        source: "images/frame.png"
        width:parent.width*2/5
        height:parent.height
        anchors.right: parent.right
        smooth:true

        Frame{
            id:player2
            anchors.centerIn: parent
            height:parent.height-10
            width:parent.width-10

            Text{
                text:"Player2"
                font.family: "Helvetica"
                font.pointSize: parent.height/3+1
                color:"#ffffff"
                anchors.verticalCenter: parent.verticalCenter
                //anchors.horizontalCenter: parent.horizontalCenter
                anchors.left: parent.left
                anchors.leftMargin: 10
            }
            Image{
                source:"images/tile_button2.png"
                width:parent.height
                height: parent.height
                smooth:true
                //anchors.horizontalCenter: parent.horizontalCenter
                anchors.right: parent.right
                opacity:{
                    if(!gameData.player1Turn)
                        1.0
                    else
                        0.1
                }
            }
            Text{
                text:gameData.countWhite
                font.family: "Helvetica"
                font.pointSize: parent.height/3+1
                color:"#ffffff"
                anchors.centerIn: parent
            }
        }
    }


}
