#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__

#include "MovingObject.h"



static const double UPPER_BOUND=95.0;
static const double LOWER_BOUND= 85.0;
const int COIN_SIZE=5;
const int BOMB_SIZE=1.2*COIN_SIZE;
const int SPL_COIN_SIZE=0.8*COIN_SIZE;

class Projectile :  public MovingObject {//
  double ptile_start_x;
  double ptile_start_y;
  double release_speed;
  double release_angle_deg;
  double ptile_ax;
  double ptile_ay;

  double ptile_speed ;/// Added by Arpon
  double ptile_angle_deg;/// Added by Arpon
  bool paused , rtheta ;
  int type;
  int level;
  const static int DEFAULT_START_LEVEL=0;
  const char * coin_color_str="GOLD";
  const char * bomb_color_str="RED";
  const char * splcoin_color_str="GREEN";

  // Moving parts
  Circle ptile_circle;

 public:
 Projectile(int init_type,double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta)
  : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    type=init_type;
    release_speed = speed;
    release_angle_deg = angle_deg;
    ptile_ax = argax;
    ptile_ay = argay;
    initProjectile();
  }



  void initProjectile();        ///Added by Arpon : Member function to initialize the Projectile
  void resetProjectile();       ///Added by Arpon : Member function to reset projectile
  void setSpeed(double);        ///Added by Arpon : Member function to set speed of projectile
  void setAngle(double );       ///Added by Arpon : Member function to set angle of projectile
  void setType(int );           ///Added by Arpon : Member function to set projectile type
  int  getType(){return type;}  ///Added by Arpon : This will be required in the lasso Class
  void setLevel(int lvl);       ///Added by Arpon :Member function to set game level

  double bound(double num)
  {

    /* Creator: Arpon Basu
     * Date : Feb 5 , 2021
     * Argument count:2
     * Argument type: double
     * Argument Condition: none
     * Return Value : double
     * Purpose: This method bound a variable, that is if variable is more than  UPPER_BOUND
     *          then it will return UPPER_BOUND , if variable is less than  LOWER_BOUND
     *          then it will return LOWER_BOUND , if variable is inbetween UPPER_BOUND and LOWER_BOUND
     *           then method will return actual variable value.
     */


     double UPPER_BOUND=95.0;
     double LOWER_BOUND= 85.0;
     double retVal=num;
     if(num<LOWER_BOUND)
     {
       retVal=LOWER_BOUND;
     }
     else if(num>UPPER_BOUND)
     {
       retVal=UPPER_BOUND;
     }
    return retVal;
  }


  void setStartingCoordinate(double x, double y)
  {
      /* Creator: Arpon Basu
       * Date : Feb 5 , 2021
       * Argument count:2
       * Argument type: double,double
       * Argument Condition: Argument must be positive real number
       * Return Value : none
       * Purpose: method to set initial coordinate of the projectile
       */
       ptile_start_x=x;
       ptile_start_y= y;
  }

}; // End class Coin

#endif
