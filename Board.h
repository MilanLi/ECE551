#ifndef __BOARD_H__
#define __BOARD_H__
#include "DataType.h"
#include <vector>

class vec{
public:
  int x;
  int y;
  vec(): x(-1), y(-1){}
  vec(int _x, int _y): x(_x), y(_y){}
  vec& operator+=(const vec& rhs){
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
  bool operator==(const vec& rhs){
    return (x == rhs.x)&&(y == rhs.y);
  }
};

const vec Direction[8] = {vec(0,1), vec(1,1), vec(1,0), vec(1,-1),
                          vec(0,-1), vec(-1,-1), vec(-1,0), vec(-1,1)};

#define DEFAULT_SIZE 8

class Board{
private:
  int boardSize;
  int blackNum;
  int whiteNum;
  pieceType** b;

  void init();
  void freeBoard();
  pieceType fetch(int, int)const;
  
  void flip(int x, int y, pieceType pt);

  bool canSetPiece(bool color);
  
public:
  int getBoardSize()const{return boardSize;}
  pieceType reverseType(pieceType pt)const;  
  pieceType turnToPieceType(bool turn)const;
  bool canFlip(int _x, int _y, pieceType pt)const;
  bool canFlip(int _x, int _y, pieceType pt, int& count)const;
  bool canFlip(int _x, int _y, pieceType pt, std::vector<vec>& v)const;
  bool turn; 
  Board():boardSize(DEFAULT_SIZE), blackNum(2), whiteNum(2), turn(false){
    init();
  }
  Board(const Board& rhs);

  ~Board(){
    freeBoard();
  }
  Board& operator=(const Board& rhs);
  void getResult(status& stat);
  bool checkEnd();
  pieceType checkTurn();
  bool setPieces(int x, int y);
  int countColor(pieceType pt);
  vec inputVec();
  void takeStep();
  void printBoard();
};

#endif
