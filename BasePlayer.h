#ifndef _BASEPLAYER_H_
#define _BASEPLAYER_H_

#include "DataType.h"
//#include "GameController.h"
#include "Board.h"
#include <string.h>

class BasePlayer{
 public:
  Board *myBoard;
  PlayerDescriptor myDescriptor;

  BasePlayer(){

  }
  BasePlayer(PlayerDescriptor descriptor,Board *board){
    myDescriptor = descriptor;
    myBoard = board;
  }

  virtual void generateMove() = 0;
  /* virtual bool canMove(){ */
  /*   return myGC->MyBoard->canFlipo(myPT); */
  /* } */
  /* virtual int countPieces(){ */
  /*   return myGC->MyBoard->countColor(myPT); */
  /* } */
};

#endif
