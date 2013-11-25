#include "gamedata.h"
//#include "Algorithm.h"
#include <QDebug>
#include <QMutex>

const int TILE_ROWS = 8;
const int TILE_COLS = 8;

GameData::GameData(QObject *parent)
    : QObject(parent)
    , m_gameOn(false)
    , m_player1Turn(true)
    , m_moves(0)
    , m_gameTimeSeconds(0)
    , m_gameTime(0,0)
    , m_time("0:00")
    , m_black(2)
    , m_white(2)
{
    // Create tiles
    for(int i = 0; i < TILE_ROWS * TILE_COLS; ++i) {
        m_tiles << new Tile;
    }

    // Timer to update the game time
    m_gameTimer = new QTimer(this);
    connect(m_gameTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
    //connect(this,SIGNAL(),this,flipcomputer());
    m_gameTimer->setInterval(1000);
}

GameData::~GameData()
{
}

int get1DIndex(int x, int y){
    return x*TILE_COLS+y;
}

vec get2DIndex(int index){
    return vec(index/TILE_COLS,index%TILE_COLS);
}

pieceType ToPieceType(Tile* t){
    if(t->hasButton1())
        return black;
    if(t->hasButton2())
        return white;
    return empty;
}

void GameData::resetGame()
{
    setMoves(0);
    foreach(Tile *t, m_tiles) {
        t->setHasButton1(false);
        t->setHasButton2(false);
        t->setHighlighted(false);
        t->setFlip(false);
    }

    tile(get1DIndex(3,3))->setHasButton2(true);
    tile(get1DIndex(4,4))->setHasButton2(true);
    tile(get1DIndex(3,4))->setHasButton1(true);
    tile(get1DIndex(4,3))->setHasButton1(true);

    b.init();

    m_flippedTiles.clear();
    m_gameTimeSeconds = 0;
    setGameTime("0:00");
    setPlayer1Turn(true);
    setGameOn(true);
    setBlack(2);
    setWhite(2);

    pieceType pt = player1Turn()? black:white;
    std::vector<vec> possibleMoves = getPossibleMoves(b, pt);
    for(int i = 0; i < (int)possibleMoves.size(); i++){
        tile(get1DIndex(possibleMoves[i].x, possibleMoves[i].y))->setFlip(true);
    }
}

void GameData::pauseGame(bool state)
{
    if (state)
        m_gameTimer->stop();
    else
        m_gameTimer->start();
}


int GameData::countBlack(){
    return b.countColor(black);
}

int GameData::countWhite(){
    return b.countColor(white);
}

bool GameData::undo(){
    return m_addedTiles.size()!=0;
}

void GameData::flipcomputer(int level){

    if(player1Turn()||!m_gameOn)
        return;
    setPlayer1Turn(!player1Turn());

    std::vector<vec> flippedPos;
    Tile* t = NULL;
    pieceType pt = player1Turn()?black:white;


    // Check for winning
    if(!b.checkEnd()){
        pieceType toMove = b.checkTurn();

        if(toMove != pt){
            setPlayer1Turn(!player1Turn());
            while(b.checkTurn()==toMove){
                vec step;
                switch(level){
                case 1: step = easyAlgorithm(b,toMove);
                    qDebug()<<"Easy algorithm, step = ("<<step.x<<", "<<step.y<<")\n";
                    break;
                case 2: step = revised_easyAlgorithm(b,toMove);
                    qDebug()<<"Normal algorithm, step = ("<<step.x<<", "<<step.y<<")\n";
                    break;
                case 3: step = mediumAlgorithm(b,toMove);
                    qDebug()<<"Medium algorithm, step = ("<<step.x<<", "<<step.y<<")\n";
                    break;
                case 4: step = hardAlgorithm(b,toMove);
                    qDebug()<<"Hard algorithm, step = ("<<step.x<<", "<<step.y<<")\n";
                    break;
                }
                //qDebug()<<"Loop gets here, step = ("<<step.x<<", "<<step.y<<")\n";
                setUndo(true);
                t = tile(get1DIndex(step.x,step.y));
                m_addedTiles << step;
                //printf("loop gets here, step = (%d, %d)!\n", step.x, step.y);
                flippedPos.clear();

                flippedPos = b.setPieces(step.x, step.y);

                setMoves(m_moves + 1);

                if (player1Turn()) {
                    t->setHasButton1(true);
                    for(int i = 0;i<(int)flippedPos.size();i++){
                        Tile *tt = tile(get1DIndex(flippedPos[i].x,flippedPos[i].y));
                        m_flippedTiles << flippedPos[i];
                        tt->setHasButton1(true);
                        tt->setHasButton2(false);
                    }
                }
                else {
                    t->setHasButton2(true);
                    for(int i = 0;i<(int)flippedPos.size();i++){
                        Tile *tt = tile(get1DIndex(flippedPos[i].x,flippedPos[i].y));
                        m_flippedTiles << flippedPos[i];
                        tt->setHasButton2(true);
                        tt->setHasButton1(false);
                    }

                }
                setBlack(countBlack());
                //emit BlackChanged();

                setWhite(countWhite());
                //emit WhiteChanged();

                if(b.checkEnd()){
                    //getResult
                    t->setHighlighted(true);
                    setGameOn(false);
                    return;
                }
            }
        }
        else
            return;
    }
    else{
        //getResult
        //t->setHighlighted(true);
        setGameOn(false);
        return;
    }

    setPlayer1Turn(!player1Turn());

    foreach(Tile *t, m_tiles) {
        t->setFlip(false);
    }
    pt = player1Turn()? black:white;
    std::vector<vec> possibleMoves = getPossibleMoves(b, pt);
    for(int i = 0; i < (int)possibleMoves.size(); i++){
        tile(get1DIndex(possibleMoves[i].x, possibleMoves[i].y))->setFlip(true);
    }
    //qDebug()<<player1Turn()<<"\n";
}

void GameData::flipHC(int index){
    if (!m_gameOn)
        return;

    Tile *t = tile(index);
    pieceType pt = player1Turn()?black:white;

    vec position = get2DIndex(index);
    std::vector<vec> flippedPos;
    if(!b.canFlip(position.x,position.y,pt,flippedPos)){
        return;
    }

    flippedPos.clear();
    flippedPos = b.setPieces(position.x,position.y);

    setMoves(m_moves + 1);

    setUndo(true);
    m_addedTiles.clear();
    m_flippedTiles.clear();
    m_addedTiles << position;

    if (player1Turn()) {
        t->setHasButton1(true);
        for(int i = 0;i<(int)flippedPos.size();i++){
            Tile *tt = tile(get1DIndex(flippedPos[i].x,flippedPos[i].y));
            m_flippedTiles << flippedPos[i];
            tt->setHasButton2(false);
            tt->setHasButton1(true);
        }
    }
    else {
        t->setHasButton2(true);
        for(int i = 0;i<(int)flippedPos.size();i++){
            Tile *tt = tile(get1DIndex(flippedPos[i].x,flippedPos[i].y));
            m_flippedTiles << flippedPos[i];
            tt->setHasButton1(false);
            tt->setHasButton2(true);
        }
    }


    //emit movesChanged();
    setBlack(countBlack());
    //emit BlackChanged();
    setWhite(countWhite());
    //emit WhiteChanged();

    setPlayer1Turn(!player1Turn());
}

void GameData::flipHH(int index)
{
    if (!m_gameOn)
        return;

    Tile *t = tile(index);

    pieceType pt = player1Turn()?black:white;

    //if (!t || t->hasButton1() || t->hasButton2())
    //  return;

    setMoves(m_moves + 1);

    vec position = get2DIndex(index);
    std::vector<vec> flippedPos;
    if(!b.canFlip(position.x,position.y,pt,flippedPos)){
        return;
    }

    flippedPos.clear();
    flippedPos = b.setPieces(position.x,position.y);

    if (player1Turn()) {
        t->setHasButton1(true);
        for(int i = 0;i<(int)flippedPos.size();i++){
            Tile *tt = tile(get1DIndex(flippedPos[i].x,flippedPos[i].y));
            tt->setHasButton1(true);
            tt->setHasButton2(false);
        }
    }
    else {
        t->setHasButton2(true);
        for(int i = 0;i<(int)flippedPos.size();i++){
            Tile *tt = tile(get1DIndex(flippedPos[i].x,flippedPos[i].y));
            tt->setHasButton2(true);
            tt->setHasButton1(false);
        }
    }
    setBlack(countBlack());
    setWhite(countWhite());

    m_addedTiles << position;
    setUndo(true);
    for(int i = 0;i<(int)flippedPos.size();i++){
        m_flippedTiles<<flippedPos[i];
    }

    // Check for winning
    if(!b.checkEnd()){
        pieceType toMove = b.checkTurn();
        if(pt != toMove){
            setPlayer1Turn(!player1Turn());
        }
    }
    else{
        //getResult
        //t->setHighlighted(true);
        setGameOn(false);
        return;
    }


    foreach(Tile *t, m_tiles) {
        t->setFlip(false);
    }
    pt = player1Turn()? black:white;
    std::vector<vec> possibleMoves = getPossibleMoves(b, pt);
    for(int i = 0; i < (int)possibleMoves.size(); i++){
        tile(get1DIndex(possibleMoves[i].x, possibleMoves[i].y))->setFlip(true);
    }
}

void GameData::flipCC(int level1, int level2)
{
    if (!m_gameOn)
        return;

    std::vector<vec> flippedPos;
    pieceType toMove = player1Turn()?black:white;
    int level = player1Turn()? level1:level2;

    while(b.checkTurn()==toMove){
        vec step;
        switch(level){
        case 1: step = easyAlgorithm(b,toMove);
            qDebug()<<"Easy algorithm, step = ("<<step.x<<", "<<step.y<<")\n";
            break;
        case 2: step = revised_easyAlgorithm(b,toMove);
            qDebug()<<"Normal algorithm, step = ("<<step.x<<", "<<step.y<<")\n";
            break;
        case 3: step = mediumAlgorithm(b,toMove);
            qDebug()<<"Medium algorithm, step = ("<<step.x<<", "<<step.y<<")\n";
            break;
        case 4: step = hardAlgorithm(b,toMove);
            qDebug()<<"Hard algorithm, step = ("<<step.x<<", "<<step.y<<")\n";
            break;
        }
        //qDebug()<<"Loop gets here, step = ("<<step.x<<", "<<step.y<<")\n";
        //setUndo(true);
        Tile* t = tile(get1DIndex(step.x,step.y));
        //m_addedTiles << step;
        //printf("loop gets here, step = (%d, %d)!\n", step.x, step.y);
        flippedPos.clear();
        //flippedPos = b.setPieces(step.x, step.y);
        flippedPos = b.setPieces(step.x,step.y);
        setMoves(m_moves + 1);

        if (player1Turn()) {
            t->setHasButton1(true);
            for(int i = 0;i<(int)flippedPos.size();i++){
                Tile *tt = tile(get1DIndex(flippedPos[i].x,flippedPos[i].y));
                m_flippedTiles << flippedPos[i];
                tt->setHasButton1(true);
                tt->setHasButton2(false);
            }
        }
        else {
            t->setHasButton2(true);
            for(int i = 0;i<(int)flippedPos.size();i++){
                Tile *tt = tile(get1DIndex(flippedPos[i].x,flippedPos[i].y));
                m_flippedTiles << flippedPos[i];
                tt->setHasButton2(true);
                tt->setHasButton1(false);
            }

        }
        setBlack(countBlack());
        //emit BlackChanged();

        setWhite(countWhite());
        //emit WhiteChanged();

        if(b.checkEnd()){
            //getResult
            t->setHighlighted(true);
            setGameOn(false);
            return;
        }
    }
    setPlayer1Turn(!player1Turn());
}


void GameData::undoTileHC()
{
    int x;
    int y;

    setUndo(false);

    while (!m_flippedTiles.empty())
    {
        //Clear button and unset highlight
        x = m_flippedTiles.last().x;
        y = m_flippedTiles.last().y;
        Tile* t = tile(get1DIndex(x, y));
        bool color = t->hasButton1();
        t->setHasButton1(!color);
        t->setHasButton2(color);
        b.set(x, y, b.reverseType(b.fetch(x,y)));

        m_flippedTiles.pop();

    }
    int addmove = m_addedTiles.size();

    while(!m_addedTiles.empty()){
        x = m_addedTiles.last().x;
        y = m_addedTiles.last().y;
        b.set(x, y, empty);//setHasButton1(false);
        tile(get1DIndex(x, y))->setHasButton1(false);
        tile(get1DIndex(x, y))->setHasButton2(false);

        m_addedTiles.pop();
    }


    setMoves(m_moves-addmove);
    setBlack(countBlack());
    //emit BlackChanged();
    setWhite(countWhite());
    //setPlayer1Turn(!player1Turn());
    //b.turn = !b.turn;

    foreach(Tile *t, m_tiles) {
        t->setFlip(false);
    }
    pieceType pt = player1Turn()? black:white;
    std::vector<vec> possibleMoves = getPossibleMoves(b, pt);
    for(int i = 0; i < (int)possibleMoves.size(); i++){
        tile(get1DIndex(possibleMoves[i].x, possibleMoves[i].y))->setFlip(true);
    }
}


void GameData::undoTileHH()
{
    setUndo(false);

    int x = m_addedTiles.last().x;
    int y = m_addedTiles.last().y;
    pieceType pt = b.fetch(x,y);

    while (!m_flippedTiles.empty())
    {
        //Clear button and unset highlight
        x = m_flippedTiles.last().x;
        y = m_flippedTiles.last().y;
        if(b.fetch(x,y)!=pt)
            break;
        Tile* t = tile(get1DIndex(x, y));
        bool color = t->hasButton1();
        t->setHasButton1(!color);
        t->setHasButton2(color);
        b.set(x, y, b.reverseType(b.fetch(x,y)));

        m_flippedTiles.pop();

    }

    while(!m_addedTiles.empty()){
        x = m_addedTiles.last().x;
        y = m_addedTiles.last().y;
        if(b.fetch(x,y)!=pt)
            break;
        b.set(x, y, empty);//setHasButton1(false);
        tile(get1DIndex(x, y))->setHasButton1(false);
        tile(get1DIndex(x, y))->setHasButton2(false);

        m_addedTiles.pop();
    }



    setMoves(m_moves-1);
    setPlayer1Turn(!player1Turn());
    b.turn = !b.turn;
    foreach(Tile *t, m_tiles) {
        t->setFlip(false);
    }
    pt = player1Turn()? black:white;
    std::vector<vec> possibleMoves = getPossibleMoves(b, pt);
    for(int i = 0; i < (int)possibleMoves.size(); i++){
        tile(get1DIndex(possibleMoves[i].x, possibleMoves[i].y))->setFlip(true);
    }


    setBlack(countBlack());
    //emit BlackChanged();
    setWhite(countWhite());
}

void GameData::updateTime()
{
    if (m_gameOn) m_gameTimeSeconds++;
    setGameTime(m_gameTime.addSecs(m_gameTimeSeconds).toString("m:ss"));
}

bool GameData::checkWin(int index, int dx, int dy, QList<Tile*> &winningTiles)
{
    int count = 0;
    for (int i=-4; i<5; ++i) {
        Tile *t = tile(index + TILE_COLS*i*dx + i*dy);
        if (t && ((player1Turn()&&t->hasButton1()) || (!player1Turn()&&t->hasButton2()))) {
            count++;
            winningTiles.append(t);
        } else {
            count = 0;
            winningTiles.clear();
        }
        if (count==5) return true;
    }
    return false;
}

