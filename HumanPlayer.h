#ifndef _HUMANPLAYER_H_
#define _HUMANPLAYER_H_

#include "DataType.h"
#include "BasePlayer.h"
#include <stdio.h>

class HumanPlayer : public BasePlayer{
 public:
 HumanPlayer(PlayerDescriptor descriptor, Board* board):BasePlayer(descriptor,board){
  
  }
  virtual void generateMove(){
    //human specific move generator
    vec step = myBoard->inputVec();
    if(step == vec(-1, -1)){
      fprintf(stderr, "no input vector!\n");
      step = myBoard->inputVec();
    }
    while(!myBoard->canFlip(step.x, step.y, myBoard->turnToPieceType(myBoard->turn))){
      fprintf(stderr, "invalid input (%d, %d)!\n", step.x, step.y);
      step =  myBoard->inputVec();
    }
    myBoard->setPieces(step.x,step.y);
    return;
  }
  
};

#endif
