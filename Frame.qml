import QtQuick 1.1

Rectangle {
    width: parent.width
    height: parent.height
    border.color: "#000000"
    border.width: 2
    radius: 10
    smooth: true

    gradient: Gradient {

        GradientStop { position: 0.0; color: "#000000" }
        GradientStop { position: 0.5; color: "#324f17" }
        GradientStop { position: 1.0; color: "#000000" }
    }


    MouseArea {
        anchors.fill: parent
        onClicked: {
            // This will just block clicks inside frame for not going into board
        }
    }
}
