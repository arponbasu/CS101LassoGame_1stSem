#include <simplecpp>
#include <string>
#include "MovingObject.h"
#include "lasso.h"
//#include "coin.h"
#include "projectile.h"

using namespace simplecpp;

void Lasso::draw_lasso_band() {  /// Arpon Note: Change look and feel of Lasso here
  double len = (release_speed/MAX_RELEASE_SPEED)*LASSO_BAND_LENGTH;
  double arad = release_angle_deg*PI/180.0;
  double xlen = len*cos(arad);
  double ylen = len*sin(arad);
  lasso_band.reset(lasso_start_x,          lasso_start_y,
                   (lasso_start_x - xlen), (lasso_start_y + ylen));
  lasso_band.setThickness(LASSO_THICKNESS);
} // End Lasso::draw_lasso_band()

void Lasso::initLasso() {
   circle_color = "red";
   loop_color = "brown";


  lasso_start_x = (PLAY_X_START + LASSO_X_OFFSET);
  lasso_start_y = (PLAY_Y_HEIGHT - LASSO_Y_HEIGHT);
  lasso_circle.reset(lasso_start_x, lasso_start_y, LASSO_SIZE);
  lasso_circle.setColor(COLOR(circle_color));//"red"
  lasso_circle.setFill(true);
  lasso_loop.reset(lasso_start_x, lasso_start_y, LASSO_SIZE/2);
  lasso_loop.setColor(COLOR(loop_color));//COLOR("brown")
  lasso_loop.setFill(true);
  addPart(&lasso_circle);
  addPart(&lasso_loop);
  lasso_looped = false;
  //the_coin = NULL;
  //num_coins = 0;
  score=0;
  isCaptured=false;
  lassoMissed=0;
  lasso_line.reset(lasso_start_x, lasso_start_y, lasso_start_x, lasso_start_y);
  lasso_line.setColor(COLOR("brown"));

  lasso_band.setColor(COLOR("BlueViolet"));

  draw_lasso_band();

} // End Lasso::initLasso()

void Lasso::yank() {
  bool paused = true, rtheta = true;
  reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
  lasso_loop.reset(lasso_start_x, lasso_start_y, LASSO_SIZE/2);
  lasso_loop.setFill(true);
  lasso_looped = false;

  if(the_projectile != NULL && isCaptured) {
    if(the_projectile->getType() == 0){
      score++;
    }
    else if(the_projectile->getType() == 1){
        score--;
    }
    else if(the_projectile->getType() == 2){
         score++;
    }
    the_projectile->resetProjectile();
    isCaptured=false;
  }
  /*
  else if(the_projectile != NULL && !isCaptured)
  {

    if(the_projectile->getType() == 2)
    {
      num_coins--;
    }


  }*/










} // End Lasso::yank()

void Lasso::loopit() {
  if(lasso_looped) { return; } // Already looped
  lasso_loop.reset(getXPos(), getYPos(), LASSO_RADIUS);
  lasso_loop.setFill(false);
  lasso_looped = true;
} // End Lasso::loopit()

void Lasso::addAngle(double angle_deg) {
  release_angle_deg += angle_deg;
  if(release_angle_deg < MIN_RELEASE_ANGLE_DEG) { release_angle_deg = MIN_RELEASE_ANGLE_DEG; }
  if(release_angle_deg > MAX_RELEASE_ANGLE_DEG) { release_angle_deg = MAX_RELEASE_ANGLE_DEG; }
  bool paused = true, rtheta = true;
  reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
} // End Lasso::addAngle()

void Lasso::addSpeed(double speed) {
  release_speed += speed;
  if(release_speed < MIN_RELEASE_SPEED) { release_speed = MIN_RELEASE_SPEED; }
  if(release_speed > MAX_RELEASE_SPEED) { release_speed = MAX_RELEASE_SPEED; }
  bool paused = true, rtheta = true;
  reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
} // End Lasso::addSpeed()

void Lasso::nextStep(double stepTime) {
  draw_lasso_band();
  MovingObject::nextStep(stepTime);
  if(getYPos() > PLAY_Y_HEIGHT) { yank(); }
  lasso_line.reset(lasso_start_x, lasso_start_y, getXPos(), getYPos());
} // End Lasso::nextStep()

void Lasso::setCircleColor(const char *str) {
   circle_color = str;
   lasso_circle.setColor(COLOR(circle_color));
}




bool Lasso::check_for_projectile(Projectile *coinPtr) {
  double lasso_x = getXPos();
  double lasso_y = getYPos();
  double ptile_x = coinPtr->getXPos();
  double ptile_y = coinPtr->getYPos();
  double xdiff = (lasso_x - ptile_x);
  double ydiff = (lasso_y - ptile_y);
  double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));

  if(distance <= LASSO_RADIUS) {
    the_projectile = coinPtr;/// the_projectile is defined in lasso.h.the_coin is now pointing to coin onject which is created in main.cpp.
    the_projectile->getAttachedTo(this);/// Calling getAttachedTo method of Projectile Class. getAttachedTo is originally method of MovingObject class which Coin has inherited
    isCaptured=true;///
  }

  return isCaptured;


} // End
