#ifndef _COMPUTERPLAYER_H_
#define _COMPUTERPLAYER_H_ 

#include "DataType.h"
#include "BasePlayer.h"
#include "Algorithm.h"
#include <stdio.h>
#include <stdlib.h>

class ComputerPlayer : public BasePlayer{
 public:
 ComputerPlayer(PlayerDescriptor descriptor,Board* board):BasePlayer(descriptor,board){
  
  }
  virtual void generateMove(){
    //computer specific move generator
    vec step = mediumAlgorithm(*myBoard, myDescriptor.pt);
    if(step == vec(-1, -1)){
      fprintf(stderr, "no step to take! check error!\n");
      
    }
    myBoard->setPieces(step.x, step.y);
    return;
  }
  
};

#endif
