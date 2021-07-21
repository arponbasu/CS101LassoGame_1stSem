#ifndef __MAIN_H__
#define __MAIN_H__

#include "projectile.h"
#include "lasso.h"

  static const int MAX_TEXT_SIZE=256;
  const int GAME_MIN_LEVEL=0;
  const int GAME_MAX_LEVEL=2;
  int coinsTossed;/// Arpon's note : this variable count of coins tossed
  int bombsTossed;/// Arpon's note : this variable count of bombs tossed
  int impTossed;/// Arpon's note : this variable count of important coin tossed
  int coinsCollected;/// Arpon's note : this variable count of  coins collected
  int bombsColled;/// Arpon's note : this variable count of  bombs collected
  int lassoThrown;/// Arpon's note : this variable count of  lasso thrown
  int lassoMissed;/// Arpon's note : this variable count of  lasso failed to collect a projectile
  int lifeLeft;/// Arpon's note : this variable count of  lives left
  int stepCount ;
  float stepTime ;
  float runTime ; //
  float currTime ;


  double release_speed ; // m/s
  double release_angle_deg ; // degrees
  double lasso_ax ;
  double lasso_ay ;
  bool paused ;
  bool rtheta ;

int level;/// Arpon's note : this variable holds game's level
double last_coin_jump_end;
string msg;

char gameStatusStr[MAX_TEXT_SIZE];
char levelTextMsg[MAX_TEXT_SIZE];
char coinScoreStr[MAX_TEXT_SIZE];
char coinTossedStr[MAX_TEXT_SIZE];
char coinsCollectedStr[MAX_TEXT_SIZE];
char statisticsStr[MAX_TEXT_SIZE];
char scoreBoardStr[MAX_TEXT_SIZE];

  void welcomeScreen();/// Arpon's note : This method creats the welcome screen
  void initializeData();/// Arpon's note : This method initializes the variables
  void setupCoordinate();/// Arpon's note : This method sets up coordinate lines
  void startPlay();/// Arpon's note : This method runs the game loop
  void setupTextBoxes();/// Arpon's note :This method setup boxes
  void updateScoreboard();

Line *X_axis,*Y_axis;
Lasso *lasso;
//  Coin *coin1;
Projectile *ptile;

 // GameLevel *gl;

  //int getZeroOne();

  Text *gameStatusText1;
  Text *levelText;
  Text *statisticsText;
  Text *scoreBoardText;
  Text *charPressed;
  Text *coinScore;
  Text *coinsCollectedText;
  Text *coinTossedText;
//  Text *statisticsText;

#endif
