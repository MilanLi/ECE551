import QtQuick 1.1

Item {
    height: 700
    width: 700

    // *** Game View ***
    GameView {
        id: gameView
        // Gameview is disabled when gameViewHider is shown
        enabled: gameViewHider.state == "hide"
    }

    // *** Game View Hider ***
    Rectangle {
        id: gameViewHider
        anchors.fill: parent
        color: "black"
        opacity: 0.7

        states: [
        State {
            name: "hide"
            when: menuPanel.state == "hide" && levelPanel.state == "hide" && demoPanel1.state == "hide" && demoPanel2.state == "hide"
            PropertyChanges {
                target: gameViewHider
                opacity: 0.0
            }
        }
        ]

        transitions: Transition {
            NumberAnimation {
                properties: "opacity"
                duration: 400
            }
        }
    }

    // *** Main Menu panel ***


    MenuPanel {
        id: menuPanel
    }

    LevelPanel{
        id:levelPanel
        state: "hide"
    }

    DemoPanel1{
        id:demoPanel1
        state: "hide"
    }

    DemoPanel2{
        id:demoPanel2
        state: "hide"
    }

    AboutPanel{
        id:aboutPanel
        state: "hide"
    }

    Dialog{
        id:resultDialog
        state:"hide"
    }
}
