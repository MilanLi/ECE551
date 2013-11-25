import QtQuick 1.1

Item {
    id: tile
    width:(parent.parent.parent.width>parent.parent.parent.height?parent.parent.parent.height:parent.parent.parent.width)/9
    height: width
    //property bool hasbutton:false

    // Tile background rectangle

    Image {
        id: lattice
        source: "images/piecenew.png"
        width:parent.width
        height:parent.height
        anchors.centerIn: parent
        smooth:true
        opacity:1.0
    }

    Image{
        id:outline
        source:"images/outline.png"
        width:parent.width
        height:parent.height
        smooth:true
        opacity:0.0
    }

    // Tile Button
    Image{

        anchors.centerIn: parent
        width:parent.width*0.9
        height:parent.height*0.9
        smooth:true
        source: {
            if (modelData.hasButton1)
                "images/tile_button1.png"
            else if (modelData.hasButton2)
                "images/tile_button2.png"
           else
                ""
        }

        opacity: modelData.hasButton1 || modelData.hasButton2

        Behavior on opacity {
            enabled: gameData.moves != 0
            NumberAnimation {
                properties: "opacity"
                duration: 0
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        enabled: !modelData.hasButton1 && !modelData.hasButton2 && modelData.canFlip
        hoverEnabled: true
        onEntered: {
            outline.opacity = 1.0
        }
        onExited: {
            outline.opacity = 0.0;
        }
        onClicked: {
            //explosion.explode()
            outline.opacity=0.0
            lattice.opacity = 1.0;
            if(menuPanel.mode == 1){
                gameData.flipHC(index);
                myTimer.restart();
            }
            else{
                gameData.flipHH(index);
                if(!gameData.gameOn)
                    resultDialog.state=""
            }
        }
    }
    Timer {
        id: myTimer
        interval:100
        onTriggered: {
            gameData.flipcomputer(levelPanel.level);
            if(!gameData.gameOn)
                resultDialog.state=""
        }
    }
}
