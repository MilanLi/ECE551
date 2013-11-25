import QtQuick 1.1

Item {
    id: gameView
    anchors.fill: parent
    width:parent.width
    height:parent.height

    // Function to center the board when starting new game
    function centerBoard() {
        centeringAnimation.start()
    }

    // *** Background image ***
    Image {
        id: backgroundImage
        source: "images/background.jpg"
        anchors.fill: parent
        smooth:true
        // Make the background "parallax scrolling"
        //x: -gameView.width/8.0 - boardFlickable.contentX/4.0
        //y: -gameView.height/8.0 - boardFlickable.contentY/4.0
    }

    Item{
        id:mainMenu
        x: (parent.height<parent.width?parent.height:parent.width)/10
        width:logo.height*0.7
        height:logo.height*0.7
        anchors.verticalCenter: logo.verticalCenter


        Image{
            anchors.centerIn: parent
            source:"images/homeButton.png"
            width:parent.width
            height:parent.height
            smooth:true
        }
        MouseArea{
            anchors.fill:parent
            onClicked:{
                menuPanel.state = ""
                gameData.pauseGame(true)
                resultDialog.state = "hide"
            }
        }
    }

    Image{
        id:logo
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins:(parent.height<parent.width?parent.height:parent.width)/18

        source:"images/logo.png"
        height:parent.height/15
        width:height*150/35
        smooth:true
    }

    Item{
        id:undobutton
        x: parent.width-(parent.height<parent.width?parent.height:parent.width)/10-undobutton.width
        width:logo.height*0.7
        height:logo.height*0.7
        anchors.verticalCenter: logo.verticalCenter
        enabled: {
            if(gameData.gameOn&&gameData.moves&&gameData.undo)
                true
            else
                false
        }
        opacity:{
            if(gameData.gameOn&&gameData.moves&&gameData.undo)
                1.0
            else
                0.3
        }
        Image{

            source:"images/undoButton.png"
            width:parent.width
            height:parent.height
            smooth:true
            anchors.centerIn: parent
        }
        MouseArea{
            anchors.fill: parent
            onClicked:{

                if(menuPanel.mode == 2)
                    gameData.undoTileHH();
                else{
                    gameData.undoTileHC();
                }
            }
        }
    }

    // *** Board ***
    Flickable {
        id: boardFlickable
        anchors.topMargin:logo.height
        anchors.fill: parent
        contentWidth: parent.width
        contentHeight: parent.height-logo.height-20
        maximumFlickVelocity: 500
        flickDeceleration: 1000

        // This implements "Fluid" 3D tilting
        /*transform: [
        Rotation {
            origin.x: gameView.width / 2
            origin.y: gameView.height / 2
            axis { x: 1; y: 0; z: 0 }
            angle: menuPanel.fluid3D ? Math.min(Math.max(-boardFlickable.verticalVelocity / 4, -75), 75) : 0
            Behavior on angle { SpringAnimation { spring: 1.5; damping: 0.75 } }
        },
        Rotation {
            origin.x: gameView.width / 2
            origin.y: gameView.height / 2
            axis { x: 0; y: 1; z: 0 }
            angle: menuPanel.fluid3D ? Math.min(Math.max(boardFlickable.horizontalVelocity / 4, -75), 75) : 0
            Behavior on angle { SpringAnimation { spring: 1.5; damping: 0.75 } }
        }
        ]*/

        Grid {
            // Board is 19x19 tiles
            id: boardGrid
            columns: 8
            spacing: 1
            anchors.horizontalCenter: parent.horizontalCenter
            Repeater {
                model: gameData.tiles
                Tile {

                }
            }
        }

        // *** Control panel ***
        InformationPanel {
            id: controlPanel
            anchors.top: boardGrid.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            width:boardGrid.width
            height: parent.height-boardGrid.height
        }
    }

    // *** Animation to center the board ***
    /*ParallelAnimation {
        id: centeringAnimation
        NumberAnimation {
            target: boardFlickable
            property: "contentX"
            to: boardFlickable.contentWidth / 2 - boardFlickable.width / 2
            duration: 1000
            easing.type: Easing.InOutQuad
        }
        NumberAnimation {
            target: boardFlickable
            property: "contentY"
            to: boardFlickable.contentHeight / 2 - boardFlickable.height / 2
            duration: 1000
            easing.type: Easing.InOutQuad
        }
    }*/


}
