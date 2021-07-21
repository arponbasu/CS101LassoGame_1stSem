#ifndef __LASSO_H__
#define __LASSO_H__

#include "MovingObject.h"

#include "projectile.h"
//#define WINDOW_X 1200
//#define WINDOW_Y 960
#define WINDOW_X 800
#define WINDOW_Y 600

#define STEP_TIME 0.05

#define PLAY_X_START 100
#define PLAY_Y_START 0
#define PLAY_X_WIDTH (WINDOW_X-PLAY_X_START)
#define PLAY_Y_HEIGHT (WINDOW_Y-100)

#define LASSO_X_OFFSET 100
#define LASSO_Y_HEIGHT 100
#define LASSO_BAND_LENGTH LASSO_X_OFFSET
#define LASSO_THICKNESS 5

#define COIN_GAP 1

#define RELEASE_ANGLE_STEP_DEG 5
#define MIN_RELEASE_ANGLE_DEG 0
#define MAX_RELEASE_ANGLE_DEG (360-RELEASE_ANGLE_STEP_DEG)
#define INIT_RELEASE_ANGLE_DEG 45

#define RELEASE_SPEED_STEP 20
#define MIN_RELEASE_SPEED 0
#define MAX_RELEASE_SPEED 200
#define INIT_RELEASE_SPEED 100

#define COIN_SPEED 120
#define COIN_ANGLE_DEG 90


#define LASSO_G 30
#define COIN_G 30

#define LASSO_SIZE 10
#define LASSO_RADIUS 150
//#define COIN_SIZE 5


const static int TYPE_COIN=0;/// Added by Arpon. Will be used in main.cpp and
const static int TYPE_BOMB=1;/// Added by Arpon. Will be used in main.cpp and
const static int TYPE_SPL_COIN=2;/// Added by Arpon.

const static int MAX_NUMBER_OF_LIFE=10;/// Added by Arpon.

class Lasso : public MovingObject {
  double lasso_start_x;
  double lasso_start_y;
  double release_speed;
  double release_angle_deg;
  double lasso_ax;
  double lasso_ay;

  // Moving parts
  Circle lasso_circle;
  Circle lasso_loop;

  // Non-moving parts
  Line lasso_line;
  Line lasso_band;

  // State info
  bool lasso_looped;
  //Coin *the_coin;
  Projectile *the_projectile;
  //int num_coins;
  int score;

  const char * circle_color;
  const char * loop_color;
  const char * line_color;
  const char * band_color;
  void initLasso();

  bool isCaptured;
  int lassoMissed;
 public:
 Lasso(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    lasso_ax = argax;
    lasso_ay = argay;
    initLasso();
  }

  void draw_lasso_band();
  void yank();
  void loopit();
  void addAngle(double angle_deg);
  void addSpeed(double speed);

  void nextStep(double t);
  //void check_for_coin(Coin *coin);
  bool check_for_projectile(Projectile  *coin);
//  int getNumCoins() { return num_coins; }
  int getScore(){return score;}
  int getMissedLassoCount(){return lassoMissed;}

  void addToScore(int point){
    score+=point;
  }
  void reduceFromScore(int point){
    score-=point;
  }

  void setCircleColor(const char *);

}; // End class Lasso

#endif
