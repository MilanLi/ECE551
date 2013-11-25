#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "Board.h"
#include <vector>
#include <math.h>
#include <stdio.h>

#define MOBILITY_RATIO 0.4
#define STABILITY_RATIO 0.5
#define POSITION_RATIO 0.4

#define INFINITY 100000


inline int whichRegion(int x, int y){
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

inline void simplify(int& x, int& y){
  if(x >= 4){
    x = 7 - x;
  }
  if(y >= 4){
    y = 7 - y;
  }
  if(x > y){
    int temp = x;
    x = y;
    y = temp;
  }
}

inline float regionScore(int x, int y){
  simplify(x, y);
  if(x == 0){
    if(y == 0) return 99;
    if(y == 1) return -8;
    if(y == 2) return 8;
    return 6;
  }
  else if(x == 1){
    if(y == 1) return -8;
    if(y == 2) return -4;
    return -3;
  }
  else if(x == 2){
    if(y == 2) return 7;
    return 4;
  }
  return 0;
}

//must ensure there exist at least one place
inline vec easyAlgorithm(const Board& b, pieceType pt){
  float evaluation = -INFINITY;
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

inline vec revised_easyAlgorithm(const Board& b, pieceType pt){
  float evaluation = -INFINITY;
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
inline vec revised_easyAlgorithm(const Board& b, pieceType pt, float& value){
  float evaluation = -INFINITY;
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

inline vec mediumAlgorithm(const Board& b, pieceType pt){
  Board newBoard;
  int bsize = b.getBoardSize();
  float totalEvaluation = -INFINITY;
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
      if(newBoard.canFlip(i, j, pt, flipPieces)){
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

inline std::vector<vec> getPossibleMoves(const Board& b, pieceType pt){
  std::vector<vec> ret;
  int bsize = b.getBoardSize();
  for(int i = 0; i < bsize; i++){
    for(int j = 0; j < bsize; j++){
      if(b.canFlip(i, j, pt)){
	ret.push_back(vec(i, j));
      }
    }
  }
  return ret;
}


inline int getMobility(const Board &board, pieceType pt){
  std::vector<vec> v;
  int result = 0;
  for(int r = 0; r < board.getBoardSize(); r++){
    for(int c = 0; c < board.getBoardSize(); c++){
      if(board.canFlip(r,c,pt,v)){
    result += (int)v.size();
      }
      v.clear();
    }
  }
  return result;
}

inline bool isPieceStableAtDirection(const Board &board,int r, int c, int rSteping, int cSteping){
  //(1,0) vertical
  //(1,1) 45 degree up-right
  //(0,1) horizontal
  //(-1,1) 45 degree down-left
  int boardSize = board.getBoardSize();
  //if(r == 0||r == boardSize-1
  // ||c == 0||c == boardSize-1)
  //return true;
  pieceType pt = board.fetch(r,c);
  bool isFull_1 = true;
  bool isFull_2 = true;
  bool isEdgeReachable_1 = true;
  bool isEdgeReachable_2 = true;
  
  //direction 1
  int rBound = rSteping>=0?boardSize-1:0;
  int cBound = cSteping>=0?boardSize-1:0;
  for(int rind = r, cind = c; (rind != rBound && cind != cBound); rind += rSteping, cind += cSteping){
    if(isEdgeReachable_1){
      if(board.fetch(rind,cind)!=pt){
	isEdgeReachable_1 = false;
      }
    }
    if(board.fetch(rind,cind)==empty){
      isFull_1 = false;
      isEdgeReachable_1 = false;
      break;
    }
  }

  //direction 2
  rSteping = -rSteping;
  cSteping = -cSteping;
  rBound = rSteping>=0?boardSize-1:0;
  cBound = cSteping>=0?boardSize-1:0;

  for(int rind = r, cind = c;(rind!=rBound&&cind!=cBound);rind+=rSteping,cind+=cSteping){
    if(isEdgeReachable_2){
      if(board.fetch(rind,cind)!=pt){
	isEdgeReachable_2 = false;
      }
    }
    if(board.fetch(rind,cind)==empty){
      isFull_2 = false;
      isEdgeReachable_2 = false;
      break;
    }
  }
  return (isFull_1&&isFull_2)||(isEdgeReachable_1||isEdgeReachable_2);
}


inline int getStability(const Board &board, pieceType pt){
  int result = 0;
  for(int r = 0;r<board.getBoardSize();r++){
    for(int c = 0;c<board.getBoardSize();c++){
      if(board.fetch(r,c)!=pt)
	continue;
      if(isPieceStableAtDirection(board,r,c,1,0)
	 &&isPieceStableAtDirection(board,r,c,1,1)
	 &&isPieceStableAtDirection(board,r,c,0,1)
	 &&isPieceStableAtDirection(board,r,c,1,-1))
	result++;
    }
  }
  return result;
}

inline float evaluateBoard(const Board &board, pieceType pt){
  pieceType oppositept = pt==black?white:black;
  int mobility = getMobility(board,pt)-getMobility(board,oppositept);
  int stability = getStability(board,pt)-getStability(board, oppositept);

  return MOBILITY_RATIO * (float)mobility + STABILITY_RATIO * (float)stability * board.getBoardSize() * 2 / 3;
}


inline float getNextMove(const Board& b, pieceType pt, bool isMaximizing, int depth, int& retX, int& retY){
  bool isFinalMove = (depth < 0);
  std::vector<vec> possibleMoves;
  bool skipTurn = false;
  
  //check who's turn
  if(!isFinalMove){
    possibleMoves = getPossibleMoves(b, pt);
    if(possibleMoves.size() == 0){
      skipTurn = true;
      possibleMoves = getPossibleMoves(b, b.reverseType(pt));
    }
    isFinalMove = (possibleMoves.size() == 0);
  }

  //if the game should finish
  if(isFinalMove){
    retX = -1;
    retY = -1;
    //b.printBoard();
    return evaluateBoard(b, pt);
  }
  else{
    //check which turn it is
    bool isNextMaximizing = !isMaximizing;
    //pt = b.reverseType(pt);
    float bestBoardValue = isMaximizing? -INFINITY: INFINITY;
    retX = -1;
    retY = -1;
    if(skipTurn){
      isNextMaximizing = isMaximizing;
      //pt = b.reverseType(pt);
      //bestBoardValue = -bestBoardValue;
    }
    
    for(int i = 0; i < (int)possibleMoves.size(); i++){
      Board newBoard = b;
      int positionScore = 0;
      int temp_x = possibleMoves[i].x;
      int temp_y = possibleMoves[i].y;
      std::vector<vec> v =newBoard.setPieces(temp_x, temp_y);
      vec dummy;
      float currentBoardValue = getNextMove(newBoard, pt, isNextMaximizing, depth-1, dummy.x, dummy.y);
      //if(depth == 0){
      //printf("at (%d, %d): mobility+stability = %f\n", temp_x, temp_y, currentBoardValue);
      //}
      for(int ind = 0;ind<(int)v.size();ind++){
	positionScore+=regionScore(v[ind].x,v[ind].y);
      }
      positionScore+=regionScore(temp_x,temp_y);
      currentBoardValue+=positionScore*POSITION_RATIO;
      //if(depth == 0){
      //	printf("at (%d, %d): overall = %f\n", temp_x, temp_y, currentBoardValue);
      //}
      if(isMaximizing){
	if(currentBoardValue > bestBoardValue){
	  bestBoardValue = currentBoardValue;
	  retX = temp_x;
	  retY = temp_y;
	}
      }
      else{
	if(currentBoardValue < bestBoardValue){
	  bestBoardValue = currentBoardValue;
	  retX = temp_x;
	  retY = temp_y;
	}
      }
    }
    return bestBoardValue;
  }
}

inline vec hardAlgorithm(const Board& b, pieceType pt){
  int depth = 3;
  bool isMaximizing = true;
  vec ret;
  getNextMove(b, pt, isMaximizing, depth, ret.x, ret.y);
  return ret;
}

#endif
