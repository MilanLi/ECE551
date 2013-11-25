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
  std::vector<vec> lastTwoFlip[2];
  vec lastTwoStep[2];
  pieceType** b;

  void freeBoard();
  void flip(int x, int y, pieceType pt);
  void flip(int x, int y, pieceType pt, std::vector<vec>& v);
  bool canSetPiece(bool color);
public:
  void init();
  void set(int, int, pieceType);
  pieceType fetch(int, int)const;
  int getBoardSize()const{return boardSize;}
  pieceType reverseType(pieceType pt)const;  
  pieceType turnToPieceType(bool turn)const;
  bool canFlip(int _x, int _y, pieceType pt)const;
  bool canFlip(int _x, int _y, pieceType pt, int& count)const;
  bool canFlip(int _x, int _y, pieceType pt, std::vector<vec>& v)const;
  bool turn;
  Board():boardSize(DEFAULT_SIZE){
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
  std::vector<vec> setPieces(int x, int y);
  int countColor(pieceType pt)const;
  vec inputVec();
  void takeStep();
  void printBoard()const;
  void regret();
};

#endif
