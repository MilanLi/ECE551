#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <QObject>
#include <QString>
#include <QList>
#include <QStack>
#include <QTime>
#include <QTimer>
#include <QDeclarativeListProperty>
#include "tile.h"
//#include "Board.h"
#include "Algorithm.h"

class GameData : public QObject
{
    Q_OBJECT

public:
    GameData(QObject *parent=0);
    ~GameData();

    Q_PROPERTY(int moves READ moves WRITE setMoves NOTIFY movesChanged);
    int moves() const {return m_moves;}
    void setMoves(int moves) {if(moves==m_moves) return; m_moves = moves; emit movesChanged();}

    Q_PROPERTY(QString gameTime READ gameTime WRITE setGameTime NOTIFY gameTimeChanged);
    QString gameTime() const {return m_time;}
    void setGameTime(const QString &time) {if(time==m_time) return; m_time = time; emit gameTimeChanged();}

    Q_PROPERTY(int countWhite READ countWhite WRITE setWhite NOTIFY WhiteChanged);
    int countWhite() const {return m_white;}
    void setWhite(int countWhite) {if(countWhite==m_white) return; m_white = countWhite; emit WhiteChanged();}

    Q_PROPERTY(int countBlack READ countBlack WRITE setBlack NOTIFY BlackChanged);
    int countBlack() const {return m_black;}
    void setBlack(int countBlack) {if(countBlack==m_black) return; m_black = countBlack; emit BlackChanged();}

    Q_PROPERTY(bool undo READ undo WRITE setUndo NOTIFY UndoChanged);
    bool undo() const {return m_undo;}
    void setUndo(bool _undo) {if(_undo==m_undo) return; m_undo = _undo; emit UndoChanged();}

    Q_PROPERTY(bool player1Turn READ player1Turn WRITE setPlayer1Turn NOTIFY player1TurnChanged);
    bool player1Turn() const {return m_player1Turn;}
    void setPlayer1Turn(bool state) {if(state==m_player1Turn) return; m_player1Turn = state; emit player1TurnChanged();}

    Q_PROPERTY(bool gameOn READ gameOn WRITE setGameOn NOTIFY gameOnChanged);
    bool gameOn() const {return m_gameOn;}
    void setGameOn(bool on) {if(on==m_gameOn) return; m_gameOn = on; emit gameOnChanged();}

    Q_PROPERTY(QDeclarativeListProperty<Tile> tiles READ tiles CONSTANT);
    QDeclarativeListProperty<Tile> tiles() {return QDeclarativeListProperty<Tile>(this, m_tiles);}

public slots:
    void resetGame();
    void pauseGame(bool state);
    int countBlack();
    int countWhite();
    void flipHH(int index);
    void flipHC(int index);
    void flipcomputer(int level);
    void flipCC(int level1, int level2);
    void undoTileHH();
    void undoTileHC();
    void updateTime();
    bool undo();

signals:
    void movesChanged();
    void gameTimeChanged();
    void player1TurnChanged();
    void gameOnChanged();
    void BlackChanged();
    void WhiteChanged();
    void UndoChanged();

private:
    Tile *tile(int index) const {return (index >= 0 && index < m_tiles.count()) ? m_tiles.at(index) : 0;}
    bool checkWin(int index, int dx, int dy, QList<Tile *> &winningTiles);

    QList<Tile *> m_tiles;
    QStack<vec> m_flippedTiles;
    QStack<vec>m_addedTiles;
    bool m_gameOn;
    bool m_player1Turn;
    int m_moves;
    int m_gameTimeSeconds;
    QTime m_gameTime;
    QTimer *m_gameTimer;
    QString m_time;
    int m_white;
    int m_black;
    bool m_undo;
    Board b;
};

#endif // GAMEDATA_H
