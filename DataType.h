#ifndef DATATYPE_H_
#define DATATYPE_H_
#include <string>

enum playerType{
  computer = 1,
  human
};

enum level{
  none = 1,
  easy,
  medium,
  hard
};

enum mode{
  hvc = 1,
  cvc,
  hvh
};

enum pieceType{
  invalid = -1,
  empty,
  black,
  white
};

enum sysStatus{
  pending = 1,
  started,
  blackWin,
  whiteWin,
  tie
};

class PlayerDescriptor{
 public:
  playerType type;
  std::string name;
  pieceType pt;
  level lv;
  
  PlayerDescriptor(){
   
  }
  PlayerDescriptor(playerType t, std::string n, pieceType p, level l){
    type = t;
    name = n;
    pt = p;
    lv = l;
  }
};

class status{
 public:
  sysStatus s;
  int black;
  int white;

  status(){
    s = pending;
    black = 2;
    white = 2;
  }
  
};

#endif
