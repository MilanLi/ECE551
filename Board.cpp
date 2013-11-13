#include "Board.h"
#include "DataType.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>

void Board::init(){
  b = new pieceType*[boardSize];
  for(int i = 0; i < boardSize; ++i){
    b[i] = new pieceType[boardSize];
      for(int j = 0;j<boardSize;++j){
	b[i][j] = empty;
      }
  }
  b[3][3] = b[4][4] = white;
  b[3][4] = b[4][3] = black;
}

Board::Board(const Board& rhs){
  boardSize = rhs.boardSize;
  blackNum = rhs.blackNum;
  whiteNum = rhs.whiteNum;
  turn = rhs.turn;
  b = new pieceType*[boardSize];
  for(int i = 0; i < boardSize; ++i){
    b[i] = new pieceType[boardSize];
    for(int j = 0;j < boardSize; ++j){
      b[i][j] = rhs.b[i][j];
    }
  }
}

Board& Board::operator=(const Board& rhs){
  if(this != &rhs){
    boardSize = rhs.boardSize;
    blackNum = rhs.blackNum;
    whiteNum = rhs.whiteNum;
    turn = rhs.turn;
    b = new pieceType*[boardSize];
    for(int i = 0; i < boardSize; ++i){
      b[i] = new pieceType[boardSize];
      for(int j = 0;j < boardSize; ++j){
	b[i][j] = rhs.b[i][j];
      }
    }
  }
  return *this;
}

void Board::freeBoard(){
  for(int i = 0; i < boardSize; ++i){
    delete[] b[i];
    }
  delete [] b;
}
pieceType Board::fetch(int x, int y)const{
  if(x < DEFAULT_SIZE && x >= 0 && y < DEFAULT_SIZE && y >= 0){
    return b[x][y];
  }
  return invalid;
}
pieceType Board::reverseType(pieceType pt)const{
  return pt == black? white: pt == white? black: pt;
}
pieceType Board::turnToPieceType(bool turn)const{
  return turn? white: black;
}

bool Board::canFlip(int _x, int _y, pieceType pt)const{ // check if somewhere is available to set piece
  if(fetch(_x, _y) != empty){
    return false;
  }
  for(int i = 0; i < boardSize; i++){
    int x(_x + Direction[i].x), y(_y + Direction[i].y);
    while(fetch(x, y) == reverseType(pt)){
      x += Direction[i].x;
      y += Direction[i].y;
    }
    if((x != _x + Direction[i].x || y != _y + Direction[i].y) && (fetch(x, y) == pt)){
      return true;
    }
  }
  return false;
}

bool Board::canFlip(int _x, int _y, pieceType pt, int& count) const{ // check if somewhere is available to set piece
  bool flag = false;
  if(fetch(_x, _y) != empty){
    count = 0;
    return flag;
  }
  for(int i = 0; i < boardSize; i++){
    int x(_x + Direction[i].x), y(_y + Direction[i].y);
    while(fetch(x, y) == reverseType(pt)){
      x += Direction[i].x;
      y += Direction[i].y;
    }
    if((x != _x + Direction[i].x || y != _y + Direction[i].y) && (fetch(x, y) == pt)){
      count++;
      flag = true;
    }
  }
  if(flag){
    return true;
  }
  return false;
}

bool Board::canFlip(int _x, int _y, pieceType pt, std::vector<vec>& v) const{ // check if somewhere is available to set piece
  bool flag = false;
  if(fetch(_x, _y) != empty){
    return flag;
  }
  for(int i = 0; i < boardSize; i++){
    int x(_x + Direction[i].x), y(_y + Direction[i].y);
    while(fetch(x, y) == reverseType(pt)){
      x += Direction[i].x;
      y += Direction[i].y;
    }
    if((x != _x + Direction[i].x || y != _y + Direction[i].y) && (fetch(x, y) == pt)){
      int x_start = _x;
      int y_start = _y;
      while((x_start = (x_start + Direction[i].x)) != x){
	y_start = y_start + Direction[i].y;
	v.push_back(vec(x_start, y_start));
      }
      flag = true;
    }
  }
  if(flag){
    return true;
  }
  return false;
}

void Board::flip(int _x, int _y, pieceType pt){
  for(int i = 0; i < 8; i++){
    int x(_x + Direction[i].x), y(_y + Direction[i].y);
    std::vector<vec> mem;
    while(fetch(x, y) == reverseType(pt)){
      mem.push_back(vec(x, y));
      x += Direction[i].x;
      y += Direction[i].y;
    }
    if((x != _x + Direction[i].x || y != _y + Direction[i].y) && (fetch(x, y) == pt)){
      for(int index = 0; index < int(mem.size()); ++index){
	if(b[mem[index].x][mem[index].y] == reverseType(pt)){
	  b[mem[index].x][mem[index].y] = pt;
	}
	else{
	  fprintf(stderr, "flipping error at (%d, %d)!\n", mem[index].x, mem[index].y);
	  exit(1);
	}
      }
    }
  }
}

bool Board::canSetPiece(bool color){ //check if one can set piece, used for checkTurn()
  pieceType pc = color? white: black;
  for(int x = 0; x < DEFAULT_SIZE; x++){
    for(int y = 0; y < DEFAULT_SIZE; y++){
      if(b[x][y] == empty && canFlip(x, y, pc)){
	return true;
      }	
    }
  }
  return false;
}

void Board::getResult(status& stat){
  int blackCount = countColor(black);
  int whiteCount = countColor(white);
  if( blackCount > whiteCount){
    stat.s = blackWin;
    stat.black = blackCount;
    stat.white = whiteCount;
    //printf("black: %d\n", countColor(black));
    //printf("white: %d\n", countColor(white));
    //printf("black wins!\n");
  }
  else if(blackCount < whiteCount){
    stat.s = whiteWin;
    stat.black = blackCount;
    stat.white = whiteCount;
    //printf("black: %d\n", countColor(black));
    //printf("white: %d\n", countColor(white));
    //printf("white wins!\n");
  }
  else{
    stat.s = tie;
    stat.black = blackCount;
    stat.white = whiteCount;
    //printf("black: %d\n", countColor(black));
    //printf("white: %d\n", countColor(white));
    //printf("ties!\n");
  }
}

bool Board::checkEnd(){
  return !(canSetPiece(turn) || canSetPiece(!turn));
}
pieceType Board::checkTurn(){
  if(canSetPiece(turn)){
    return turnToPieceType(turn);
  }
  else if(canSetPiece(!turn)){
    turn = !turn;
    return turnToPieceType(turn);
  }
  else{
    std::cerr << "should have won, check error!\n";
    exit(1);
  }
}
bool Board::setPieces(int x, int y){
  if(canFlip(x, y, turnToPieceType(turn))){
    b[x][y] = turnToPieceType(turn); //set piece  
    flip(x, y, turnToPieceType(turn)); // flip around
    turn = !turn;
    return true;
  }
  return false;
}
int Board::countColor(pieceType pt){
  int count = 0;
  for(int i = 0; i < DEFAULT_SIZE; ++i){
    for(int j = 0; j < DEFAULT_SIZE; ++j){
      if(b[i][j] == pt){
	count++;
      }
    }
  }
  return count;
}

void skipSpace(char* p){
  while(isspace(*p)){
    p += 1;
  }
}

vec Board::inputVec(){
  vec def(-1, -1);
  char* line = NULL;
  size_t len = 0;
  if(turn){
    printf("white's turn : please input a vector (devided by ','): ");
  }
  else{
    printf("black's turn : please input a vector (devided by ','): ");
  }
  if(getline(&line, &len, stdin) == -1){
    fprintf(stderr, "get line %s error!\n", line);
    exit(1);
  }
  char* startp = line;
  char* endp;
  long num1 = strtol(startp, &endp, 10);
  if(endp == startp){
    fprintf(stderr, "no first number!\n");
    exit(1);
  }
  skipSpace(endp);
  endp++; // skip ','
  startp = endp;
  long num2 = strtol(startp, &endp, 10);
  if(endp == startp){
    fprintf(stderr, "no second number!\n");
    exit(1);
  }
  free(line);
  def.x = int(num1);
  def.y = int(num2);
  return def;
}

void Board::takeStep(){
  checkTurn();
  vec step = inputVec();
  if(step == vec(-1, -1)){
    fprintf(stderr, "no input vector!\n");
    step = inputVec();
  }
  while(!canFlip(step.x, step.y, turnToPieceType(turn))){
    fprintf(stderr, "invalid input (%d, %d)!\n", step.x, step.y);
    step = inputVec();
  }
  setPieces(step.x, step.y);
  if(checkEnd()){
    if(countColor(black) > countColor(white)){
      printf("black: %d\n", countColor(black));
      printf("white: %d\n", countColor(white));
      printf("black wins!\n");
    }
    else if(countColor(black) < countColor(white)){
      printf("black: %d\n", countColor(black));
      printf("white: %d\n", countColor(white));
      printf("white wins!\n");
    }
    else{
      printf("black: %d\n", countColor(black));
      printf("white: %d\n", countColor(white));
      printf("ties!\n");
    }
    printBoard();
    exit(0);
  }
  else{
    printBoard();
  }
}

void Board::printBoard(){
  printf("=========================\n|         Board        |\n=========================\n\n");
  for(int i = 0; i < DEFAULT_SIZE; ++i){
    printf("%d ", i);
    for(int j = 0; j < DEFAULT_SIZE; ++j){
      if(b[i][j] == white){
	printf("O ");
      }
      else if(b[i][j] == black){
	printf("X ");
      }
      else{
	printf(". ");
      }
    }
    printf("\n\n");
  }
  printf("  0 1 2 3 4 5 6 7 \n");
}

// int main(void){
//   Board b;
//   vec pos;
//   b.printBoard();
//   while(1){
//     b.takeStep(); 
//   }
//   return 0;
// }
