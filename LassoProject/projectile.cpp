//Improvement of coin class. Includes bomb and special coin.

#include "projectile.h"
#include "lasso.h"

#include <time.h> /// Code Added by Arpon
#include <iostream>/// Code Added by Arpon
using namespace std;/// Code Added by Arpon

void Projectile::initProjectile() {

  srand( (unsigned)time( NULL ) );///Code Added by Arpon. Required for random number initialization


  ptile_start_x = (PLAY_X_START+WINDOW_X)/2;
  ptile_start_y = PLAY_Y_HEIGHT;
  setLevel(DEFAULT_START_LEVEL);///Code Added by Arpon.Setting default start level.
  setType(type);///Code Added by Arpon.Setting projectile type
  addPart(&ptile_circle);
}

void Projectile::resetProjectile() {
   //ptile_speed = ((unsigned)time( NULL )%2 + (float) rand()/RAND_MAX)*ptile_SPEED; // code modified by Arpon
   /// code modified by Arpon
 // double ptileangle_deg = ((float) rand()/RAND_MAX)*(2*COIN_ANGLE_DEG);/// code modified by Arpon

 if(level>=2){ ///Code Added by Arpon.If level is 2 or higher then speed will be variable.Variable speed is achieved by random number
    ptile_speed = ((unsigned)time( NULL )%2 + (float) rand()/RAND_MAX)*COIN_SPEED;
 }
 else{ /// For Level 0 and 1 Speed of the projectile will remain constant
   ptile_speed = COIN_SPEED;
 }

  if(level>=1){///Code Added by Arpon.For level 1 and higher projectile angle will change.
    ptile_angle_deg = bound(rand()%180);
  }
  else{/// For Level 0 angle of the projectile remains constant throughout the level
    ptile_angle_deg = (1*COIN_ANGLE_DEG);
  }



  ptile_ax = 0;///
  ptile_ay = COIN_G;
  paused = true, rtheta = true;
  reset_all(ptile_start_x, ptile_start_y,
            ptile_speed, ptile_angle_deg, ptile_ax, ptile_ay,
            paused, rtheta);// This method is defined in movingobject.h
}

void Projectile::setSpeed(double spd)
{

  /* Creator: Arpon Basu
   * Date : Feb 1 , 2021
   * Argument count:1
   * Argument type: double
   * Argument Condition: Argument must be positive real number
   * Return Value : none
   * Purpose: method to set the speed of the projectile.
   */
   if(spd>0){
     ptile_speed=spd;
      paused = true, rtheta = true;
     reset_all(ptile_start_x, ptile_start_y,
               ptile_speed, ptile_angle_deg,
               ptile_ax, ptile_ay, paused, rtheta);// This method is defined in movingobject.h
   }



}

void Projectile::setAngle(double ang_deg)
{

  /* Creator: Arpon Basu
   * Date : Feb 1 , 2021
   * Argument count:1
   * Argument type: double
   * Argument Condition: Argument must be a real number between -180 to 180
   * Return Value : none
   * Purpose: method to set the angle of the projectile.
   */
   if(ang_deg>-180 && ang_deg<180 )
   {
    ptile_angle_deg=ang_deg;
    paused = true, rtheta = true;
   reset_all(ptile_start_x, ptile_start_y,
             ptile_speed, ptile_angle_deg,
             ptile_ax, ptile_ay,
             paused, rtheta);// This method is defined in movingobject.h
    }

}


void Projectile::setType(int tp)
{
  /* Creator: Arpon Basu
   * Date : Feb 1 , 2021
   * Argument count:1
   * Argument type: int
   * Argument Condition: Argument must be a non negative integer
   * Return Value : none
   * Purpose: method to set the type of projectile.
   *          Normal Coin Type  =0
   *          Bomb        Type  =1
   *          Special Coin Type =2
   */
type=tp;
if(type==TYPE_COIN){
  ptile_circle.reset(ptile_start_x, ptile_start_y, COIN_SIZE);
  ptile_circle.setColor(COLOR(coin_color_str));
}
else if(type==TYPE_BOMB){
  ptile_circle.reset(ptile_start_x, ptile_start_y, BOMB_SIZE);
  ptile_circle.setColor(COLOR(bomb_color_str));
}
else if(type==TYPE_SPL_COIN){
  ptile_circle.reset(ptile_start_x, ptile_start_y,SPL_COIN_SIZE);
  ptile_circle.setColor(COLOR(splcoin_color_str));
}

ptile_circle.setFill(true);

}


void Projectile::setLevel(int lvl){
  /* Creator: Arpon Basu
   * Date : Feb 1 , 2021
   * Argument count:1
   * Argument type: int
   * Argument Condition: Argument must be a non negative integer
   * Return Value : none
   * Purpose: method to set the level of game.

   */

   level=lvl;
}
