#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "Board.h"
#include <vector>

int whichRegion(int x, int y){
  if((x == 0 || x == 7) && (y == 0 || y == 7)){
    return 5;
  }
  else if((x <= 5 && x >= 2) && (y <= 5 && y >= 2)){
    return 1;
  }
  else if((x == 1 || x == 6) && (y == 1 || y == 6)){
    return 4;
  }
  else if((x <= 1 || x >= 6) && (y <=1 || y >= 6)){
    return 6;
  }
  else if( (x < 1 || x > 6) || (y < 1 || y > 6)){
    return 3;
  }
  else{
    return 2;
  }
}

float regionScore(int x, int y){
  int reg = whichRegion(x, y);
  switch(reg){
  case 6:
    return -6;
  case 5:
    return 10;
  case 4:
    return -8;
  case 3:
    return 6;
  case 2:
    return -2;
  default:
    return 0;
  }
}

//must ensure there exist at least one place
vec easyAlgorithm(const Board& b, pieceType pt){
  float evaluation = -100;
  vec ret;
  for(int i = 0; i < b.getBoardSize(); i++){
    for(int j = 0; j < b.getBoardSize(); j++){
      int count = 0;
      if(b.canFlip(i, j, pt, count)){
	float eval = (float)count * 0.5 + regionScore(i, j) * 1;
	if(eval > evaluation){
	  evaluation = eval;
	  ret = vec(i, j);
	}
      }
    }
  }
  return ret;
}

vec revised_easyAlgorithm(const Board& b, pieceType pt){
  float evaluation = -100;
  std::vector<vec> flipPieces;
  vec ret;
  for(int i = 0; i < b.getBoardSize(); i++){
    for(int j = 0; j < b.getBoardSize(); j++){
      flipPieces.clear();
      flipPieces.push_back(vec(i, j));
      float eval = 0;;
      if(b.canFlip(i, j, pt, flipPieces)){
	//calculate the evaluation based on the region scores
	for(int k = 0; k < int(flipPieces.size()); k++){
	  eval += regionScore(flipPieces[k].x, flipPieces[k].y);
	}
	//check if update is needed.
	if(eval > evaluation){
	  evaluation = eval;
	  ret = flipPieces[0];
	}
      }
    }
  }
  return ret;
}

//overloaded function to get the value by the way
vec revised_easyAlgorithm(const Board& b, pieceType pt, float& value){
  float evaluation = -100;
  std::vector<vec> flipPieces;
  vec ret;
  for(int i = 0; i < b.getBoardSize(); i++){
    for(int j = 0; j < b.getBoardSize(); j++){
      flipPieces.clear();
      flipPieces.push_back(vec(i, j));
      float eval = 0;;
      if(b.canFlip(i, j, pt, flipPieces)){
	//calculate the evaluation based on the region scores
	for(int k = 0; k < int(flipPieces.size()); k++){
	  eval += regionScore(flipPieces[k].x, flipPieces[k].y);
	}
	//check if update is needed.
	if(eval > evaluation){
	  evaluation = eval;
	  ret = flipPieces[0];
	}
      }
    }
  }
  value = evaluation;
  return ret;
}

vec mediumAlgorithm(const Board& b, pieceType pt){
  Board newBoard;
  int bsize = b.getBoardSize();
  float totalEvaluation = -100;
  std::vector<vec> flipPieces;
  vec ret;
  //vec temp;
  for(int i = 0; i < bsize; i++){
    for(int j = 0; j < bsize; j++){
      flipPieces.clear();
      flipPieces.push_back(vec(i, j));
      float eval = 0;
      newBoard = b;
      //for each candidate for pt  
      if(b.canFlip(i, j, pt, flipPieces)){
	//calculate the evaluation based on the region scores
	for(int k = 0; k < int(flipPieces.size()); k++){
	  eval += regionScore(flipPieces[k].x, flipPieces[k].y);
	}
	//set that piece
	newBoard.setPieces(i, j);
	//check if it ends
	//if it ends, just return;
	if(newBoard.checkEnd()){
	  return vec(i, j);
	}
	//if not, check whose turn it is
	else{
	  pieceType t = newBoard.checkTurn();
	  ////if it is reverse(pt)'s turn
	  ////evaluate for the best step for -pt, store the negative of evaluation.
	  if(t == newBoard.reverseType(pt)){
	    float val = 0;
	    revised_easyAlgorithm(newBoard, t, val);
	    eval -= val;
	  }
	  //if it is pt's turn
	  //evaluate for the best step for pt and store step and evaluation.
	  else{
	    float val = 0;
	    revised_easyAlgorithm(newBoard, t, val);
	    eval += val;
	  }
	}
	if(eval > totalEvaluation){
	  totalEvaluation = eval;
	  ret = vec(i, j);
	}
      }
    }
  }
  return ret;
}


#endif
