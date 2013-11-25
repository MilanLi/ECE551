CONFIG -= app_bundle

SOURCES = main.cpp \
    mainwidget.cpp \
    gamedata.cpp \
    Board.cpp

QT += script \
    declarative

# This is needed for Maemo5 to recognize minimization of the application window
maemo5 {
    QT += dbus
}

contains(QT_CONFIG, opengles2)|contains(QT_CONFIG, opengl):QT += opengl
sources.files = $$SOURCES \
    $$HEADERS \
    $$RESOURCES \
    $$FORMS \
    Reversi.pro

OTHER_FILES += content/MainView.qml \
    content/Tile.qml \
    content/ControlPanel.qml \
    content/Button.qml \
    content/MenuPanel.qml \
    content/GameView.qml \
    content/Switch.qml \
    content/Frame.qml \
    content/AboutPanel.qml \
    content/Dialog.qml \
    content/LevelPanel.qml \
    content/InformationPanel.qml \
    content/DemoPanel1.qml \
    content/DemoPanel2.qml

HEADERS += tile.h \
    mainwidget.h \
    gamedata.h \
    DataType.h \
    Board.h \
    Algorithm.h
