#include <simplecpp>
#include <string>
#include "main.h"
#include "MovingObject.h"

#include "projectile.h"//Included by Arpon

#include <time.h> /// Code Added by Arpon
#include <iostream>/// Code Added by Arpon

using namespace simplecpp;


int LEVEL0_LASSO_AVAILABLE =5;
int LEVEL0_COIN_AVAILABLE=LEVEL0_LASSO_AVAILABLE;

int LEVEL1_LASSO_AVAILABLE =5;
int LEVEL1_COIN_AVAILABLE=LEVEL1_LASSO_AVAILABLE;

int LEVEL2_LASSO_AVAILABLE =5;
int LEVEL2_COIN_AVAILABLE=LEVEL2_LASSO_AVAILABLE;

/*
int getZeroOne() // Returns 0 or 1. Used for coin toss
{
  return rand()%2;
}
*/

int randbw(int a, int b)
{
  /* arguments:2 (int , int)
     returns : int
     Purpose: Generate random number between the given arguments(including both)
  */

  return (a + rand()%(b - a + 1));
}


//main_program {
int main(int argc,char *argv[]){
  srand( (unsigned)time( NULL ) ); ///Arpon's Note:Initializing random number

  initCanvas("Lasso Press h for help", WINDOW_X, WINDOW_Y);///Arpon's Note: initializing canvas
  welcomeScreen();///Arpon's Note:Calling function to create welcome screen upon starting of the game
  initializeData();///Arpon's Note:Initializing data
  setupCoordinate();///Arpon's Note:Setting up coordinate axis
  setupTextBoxes();
  ///Arpon Note: creating lasso object of Lasso Class
  lasso = new Lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);//pointer to lasso class





  //string msg("Cmd(t/l/y): _");///modified by Arpon
//  msg.setMessage("Cmd(t/l/y): _");
  msg="Cmd(t/l/y): _";
  //Text charPressed(PLAY_X_START + 50, PLAY_Y_HEIGHT + 20, msg);///Arpon's Note: Creating an object of Text class name charPressed
  charPressed=new Text (PLAY_X_START + 50, PLAY_Y_HEIGHT + 20, msg);///Arpon's Note: Creating an object of Text class name charPressed


  sprintf(coinScoreStr, "Coins: %d", lasso->getScore());
//  Text coinScore(PLAY_X_START, PLAY_Y_HEIGHT + 50, coinScoreStr);///Arpon's Note: Creating an object of Text class name coinScore
   coinScore=new Text (PLAY_X_START, PLAY_Y_HEIGHT + 50, coinScoreStr);///Arpon's Note: Creating an object of Text class name coinScore


  /// Codes Added by Arpon:

  sprintf(scoreBoardStr, "Coins Tossed: %d",coinsTossed );
  //Text coinTossedText(PLAY_X_START+100, PLAY_Y_HEIGHT+80, coinTossedStr);///Arpon's Note: Creating an object of Text class name coinScore
  coinTossedText=new Text (PLAY_X_START+100, PLAY_Y_HEIGHT+80, coinTossedStr);///Arpon's Note: Creating an object of Text class name coinScore

  //scoreBoardText=new Text(PLAY_X_START+100, PLAY_Y_HEIGHT+80, scoreBoardStr);

/// Codes Added by Arpon:

  sprintf(coinsCollectedStr, "Coins Collected: %d",coinsTossed );
  //Text coinsCollectedText(PLAY_X_START + 400, PLAY_Y_HEIGHT + 80, coinsCollectedStr);///Arpon's Note: Creating an object of Text class name coinScore
 coinsCollectedText=new  Text(PLAY_X_START + 400, PLAY_Y_HEIGHT + 80, coinsCollectedStr);///Arpon's Note: Creating an object of Text class name coinScore



  /// Codes Added by Arpon:
    //char gameStatusStr[256];
    sprintf(gameStatusStr, "Games Running. Current Level:%d" ,level);
    //Text gameStatusText(PLAY_X_START + 600, PLAY_Y_HEIGHT - 400, gameStatusStr);///Arpon's Note: Creating an object of Text class name coinScore

    gameStatusText1=new Text(PLAY_X_START + 600, PLAY_Y_HEIGHT - 400, gameStatusStr);
    //gameStatusText.setVisible(false);

  //  gameStatusText1=new Text(PLAY_X_START+200, PLAY_Y_HEIGHT-400, gameStatusStr);

  levelText->setMessage("");

  //Text statisticsText(PLAY_X_START + 600, PLAY_Y_HEIGHT - 420, "");///Arpon's Note: Creating an object of Text class name coinScore
  statisticsText=new Text (PLAY_X_START + 600, PLAY_Y_HEIGHT - 420, "");///Arpon's Note: Creating an object of Text class name coinScore


  paused = true; rtheta = true;

  double ptile_speed = COIN_SPEED;
  double ptile_angle_deg = COIN_ANGLE_DEG;
  double ptile_ax = 0;
  double ptile_ay = COIN_G;


  int initial_type = TYPE_COIN; //0 = coin , 1 = bomb, 2 = special coin


  ptile = new Projectile(initial_type,ptile_speed , ptile_angle_deg,
                                      ptile_ax, ptile_ay, paused, rtheta);


  // After every COIN_GAP sec, make the coin jump
  last_coin_jump_end = 0;



 ptile->setLevel(level);

/*  for(;;) {

      if((runTime > 0) && (currTime > runTime)) { break; }

      if(coinsTossed == LEVEL1_COIN_AVAILABLE + 1)
      {
         sprintf(gameStatusStr, "%s","Level Over" );
         gameStatusText.setMessage(gameStatusStr);
         ptile->pause();

         for(int i = 0; i < 3; i++)
         {
           gameStatusText.setMessage("");
           wait(0.5);
           gameStatusText.setMessage(gameStatusStr);
           wait(0.5);
          }

         break;
       }

      XEvent e;  /// Arpon Note: Creating an X event
      bool pendingEv = checkEvent(e);

      if(pendingEv) {
        char c = charFromEvent(e);  /// Arpon Note: reading command from console
        msg[msg.length()-1] = c;
        charPressed.setMessage(msg);

        switch(c) {

      case 'h' :
            /// Arpon's Note:task to be carried out upon receiving h

            //std::system("./lassohelp");
            std::system("nano projectile.h.txt");

           break;
      case 't':
            /// Arpon's Note:task to be carried out upon receiving t
        //charPressed.setMessage("   t(throwing Lasso):");
        lassoThrown++;
        sprintf(coinTossedStr, "Coins Tossed: %d Bombs Tossed: %d Imp Tossed:%d Lasso Thrown:%d ", coinsTossed,bombsTossed,impTossed,lassoThrown);
        coinTossedText.setMessage(coinTossedStr);
        lasso->unpause();/// Arpon's Note: unpause function is inherited from Movingobject class

  	break;

    case 'y':
    sprintf(coinTossedStr, "Coins Tossed: %d Bombs Tossed: %d Imp Tossed:%d Lasso Thrown:%d ", coinsTossed,bombsTossed,impTossed,lassoThrown);
    coinTossedText.setMessage(coinTossedStr);
  	    lasso->yank();/// Arpon's Note: yank function is inherited from Movingobject class
      //  updateScoreboard();
  	break;


        case 'l':
  	    lasso->loopit(); // look at line 54 of lasso.cpp for implementation details.

        if(!lasso->check_for_projectile(ptile)) {
          lassoMissed++;
          lifeLeft = lifeLeft-lassoMissed;
        }
  	    wait(STEP_TIME*5);
        //lifeLeft=lifeLeft-lasso->getMissedLassoCount();

  	  break;

        case '[':

  	        if(lasso->isPaused()) { lasso->addAngle(-RELEASE_ANGLE_STEP_DEG);	}

  	   break;
        case ']':

  	        if(lasso->isPaused()) { lasso->addAngle(+RELEASE_ANGLE_STEP_DEG); }
  	  break;
        case '-':
  	        if(lasso->isPaused()) { lasso->addSpeed(-RELEASE_SPEED_STEP); }
  	  break;

        case '=':
  	        if(lasso->isPaused()) { lasso->addSpeed(+RELEASE_SPEED_STEP); }
  	  break;
        case 'q':
              charPressed.setMessage("Got q.  Quitting.  See you soon  ");
              wait(5);
  	          exit(0);
        default:
  	break;
        }
      }

      lasso->nextStep(stepTime);
      ptile->nextStep(stepTime);

      sprintf(statisticsStr, "x: %f y:%f ",ptile->getXCurrent(),ptile->getYCurrent() );

      statisticsText.setMessage(statisticsStr);

      if(ptile->isPaused()) {
        if((currTime-last_coin_jump_end) >= COIN_GAP) {
          /// Codes Added by Arpon:



        int num = randbw(0,2);



        if(num == TYPE_COIN) {
          coinsTossed++;
        }
        else if (num == TYPE_BOMB){
          bombsTossed++;
        }
        else if (num == TYPE_SPL_COIN){
          impTossed++;
        }

        sprintf(coinTossedStr, "Coins Tossed: %d Bombs Tossed: %d Imp Tossed:%d Lasso Thrown:%d ", coinsTossed,bombsTossed,impTossed,lassoThrown);
        coinTossedText.setMessage(coinTossedStr);
      // updateScoreboard();
        /// end


        ptile->setType(num);/// Arpon's Note: Informing ptile object about type
  	    ptile->unpause();
        }
      }

      if(ptile->getYPos() > PLAY_Y_HEIGHT ) {

        if(ptile->getType() == TYPE_SPL_COIN) {
          lasso->reduceFromScore(1) ;
        }

        ptile->resetProjectile();
        last_coin_jump_end = currTime;
        /// Codes Added by Arpon:

      }

      sprintf(coinScoreStr, "Current Score: %d",lasso->getScore());
      coinScore.setMessage(coinScoreStr);

      /// Codes Added by Arpon:
      sprintf(coinsCollectedStr, "Coins Collected: %d", lasso->getScore());
      coinsCollectedText.setMessage(coinsCollectedStr);

      stepCount++;
      currTime += stepTime;
      wait(stepTime);
    } // End for(;;)*/

 startPlay();
  wait(3);


} // End main_program


void initializeData()
{
  /* Creator: Arpon Basu
   * Date : Feb 5 , 2021
     arguments:none
     returns : none(void)
     Purpose: Initializes run data
  */
  coinsTossed = 0;
  bombsTossed = 0;
  impTossed = 0;
  coinsCollected = 0;
  lassoThrown = 0;
  lassoMissed = 0;
  lifeLeft = MAX_NUMBER_OF_LIFE;/// MAX_NUMBER_OF_LIFE is defined in lasso.h



  stepCount = 0;
  stepTime = STEP_TIME;
  runTime = -1; // sec; -ve means infinite
  currTime = 0;

  // Draw lasso at start position
  release_speed = INIT_RELEASE_SPEED; // m/s
  release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
  lasso_ax = 0;
  lasso_ay = LASSO_G;
  paused = true;
  rtheta = true;

}


void welcomeScreen()
{
  /* Creator: Arpon Basu
   * Date : Feb 5 , 2021
     arguments:none
     returns : none(void)
     Purpose: Generate Welcome introductory screen
  */
  sprintf(levelTextMsg, "%s","Welcome to Lasso Game. This game is a modificaton of Original Lasso Game by Arpon Basu" );//Prints string
  XEvent e1;  /// Arpon Note: Creating an X event


  levelText = new Text(PLAY_X_START + 200, PLAY_Y_HEIGHT - 400, levelTextMsg);
  levelText->setColor(COLOR("blue"));


  wait(3);
  sprintf(levelTextMsg,"%s" ,"Enter between 0 to 2 within 3 sec. In case of no keypress will proceed to Level 0");
  levelText->setMessage(levelTextMsg);
  wait(3);
  bool pendingEv1 = checkEvent(e1);
  char c1 = 0 ;
  if(pendingEv1){
   c1 = charFromEvent(e1);
  }

  int rcvd_num = c1 - 48;
  if(rcvd_num < 0) rcvd_num = 0;


  if(rcvd_num > 2){
  level = 2;
  }
  else if(rcvd_num<0){
  level = 0;
  }
  else{
  level = rcvd_num;
  }

  sprintf(levelTextMsg, "Received :%d Setting Level :%d", rcvd_num, level);
  levelText->setMessage(levelTextMsg);

  //sprintf(levelTextMsg, "Setting Level :%d",level );
  levelText->setMessage(levelTextMsg);
  wait(3);

}


void setupCoordinate(){


  /* Creator: Arpon Basu
   * Date : Feb 10 , 2021
   * Argument count:none
   * Argument type: none
   * Argument Condition: N/A
   * Return Value : none
   * Purpose: method setup coordinate axis
   */
   X_axis=new Line(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
   X_axis->setColor(COLOR("blue"));
   Y_axis=new Line (PLAY_X_START, 0, PLAY_X_START, WINDOW_Y-100);
   Y_axis->setColor(COLOR("blue"));
}

void setupTextBoxes(){


}

void updateScoreboard()
{
  sprintf(scoreBoardStr, "Coins Tossed: %d Bombs Tossed: %d Imp Tossed:%d Lasso Thrown:%d ", coinsTossed,bombsTossed,impTossed,lassoThrown);
  scoreBoardText->setMessage(coinTossedStr);
}


void startPlay()
{
  /* Creator: Arpon Basu
   * Date : Feb 10 , 2021
   * Argument count:none
   * Argument type: none
   * Argument Condition: N/A
   * Return Value : none
   * Purpose: method to run play loop
   */

    if(level>2) /// Arpon's Note: Checking that all levels are over or not
    {
      ///Arpon's Note:All the levels are over. Displaying message and exiting
      sprintf(gameStatusStr, "You have completed all three levels. Your Score is = %d.Quiting in 3 sec.", lasso->getScore());
      gameStatusText1->setMessage(gameStatusStr);
      gameStatusText1->move( -300, PLAY_Y_HEIGHT - 400);
      wait(5);
      exit(0);
    }

  ptile->setLevel(level);///Arpon's Note:Setting level info to projectile object

   for(;;) {  /// Arpon's Note: Starting game loop

       if((runTime > 0) && (currTime > runTime)) { break; }

       if(lassoThrown >5) /// Arpon's Note:Checking whether lasso count , hence game level is over or not
       {
          sprintf(gameStatusStr, "%s","Level Over" );
          gameStatusText1->setMessage(gameStatusStr);
          ptile->pause();

         /// Arpon's Note: Creating blinking message
          int blink_count=3;
          float wait_time=0.5;
          for(int i = 0; i < blink_count; i++)
          {
            gameStatusText1->setMessage("");
            wait(wait_time);
            gameStatusText1->setMessage(gameStatusStr);
            wait(wait_time);
           }

            level++;/// Arpon's Note:Increasing level
            /// Arpon's Note: Resrtting data to start new level
            lassoThrown=0;
            coinsTossed=0;
            bombsTossed=0;
            impTossed=0;
            sprintf(gameStatusStr, "Moving to level %d",level );
            gameStatusText1->setMessage(gameStatusStr);

            startPlay();/// Starting game loop
          break;
        }
        else
        {
          ///Arpon's note: Game level is not over.Displaying level
          sprintf(gameStatusStr, "Games Running. Current Level:%d" ,level);
          gameStatusText1->setMessage(gameStatusStr);
        }



       XEvent e;  /// Arpon's Note: Creating an X event
       bool pendingEv = checkEvent(e);

       if(pendingEv) {
         char c = charFromEvent(e);  /// Arpon Note: reading command from console
         msg[msg.length()-1] = c;
         charPressed->setMessage(msg);

         switch(c) {

       case 'h' :
             /// Arpon's Note:task to be carried out upon receiving h

             //std::system("./lassohelp");
             //std::system("nano projectile.h.txt");
             std::system("cat help_lasso &");
             std::system("google-chrome-stable help.pdf &");
            break;
       case 't':
        /// Arpon's Note:task to be carried out upon receiving t
         lassoThrown++;/// Arpon's Note: Increasing Lasso thrown count
         /// Arpon's Note: Updating text box info
         sprintf(coinTossedStr, "Coins Tossed: %d Bombs Tossed: %d Imp Tossed:%d Lasso Thrown:%d ", coinsTossed,bombsTossed,impTossed,lassoThrown);
         coinTossedText->setMessage(coinTossedStr);
         /// Arpon's Note:Calling to unpause lasso. During game this will now display the moving lasso
         lasso->unpause();/// Arpon's Note: unpause function is inherited from Movingobject class

     break;

     case 'y':
     /// Arpon's Note:task to be carried out upon receiving t
      sprintf(coinTossedStr, "Coins Tossed: %d Bombs Tossed: %d Imp Tossed:%d Lasso Thrown:%d ", coinsTossed,bombsTossed,impTossed,lassoThrown);
      coinTossedText->setMessage(coinTossedStr);
/// Arpon's Note: yank function is inherited from Movingobject class
/// Arpon's Note: During game pressing y will pull back the lasso
      lasso->yank();
     break;


         case 'l':
         lasso->loopit(); // look at line 54 of lasso.cpp for implementation details.
         lasso->check_for_projectile(ptile);

         /*if(!lasso->check_for_projectile(ptile)) {
           lassoMissed++;
           lifeLeft = lifeLeft-lassoMissed;
         }*/

         wait(STEP_TIME*5);

       break;

         case '[':

             if(lasso->isPaused()) { lasso->addAngle(-RELEASE_ANGLE_STEP_DEG);	}

        break;
         case ']':

             if(lasso->isPaused()) { lasso->addAngle(+RELEASE_ANGLE_STEP_DEG); }
       break;
         case '-':
             if(lasso->isPaused()) { lasso->addSpeed(-RELEASE_SPEED_STEP); }
       break;

         case '=':
             if(lasso->isPaused()) { lasso->addSpeed(+RELEASE_SPEED_STEP); }
       break;
         case 'q':
               charPressed->setMessage("Got q.Quitting. See you soon  ");
               wait(5);
               exit(0);
         default:
     break;
         }
       }

       lasso->nextStep(stepTime);
       ptile->nextStep(stepTime);

       sprintf(statisticsStr, "y:%f ",ptile->getYCurrent() );

      // statisticsText.setMessage(statisticsStr);
      statisticsText->setMessage(statisticsStr);


       if(ptile->isPaused()) {
         if((currTime-last_coin_jump_end) >= COIN_GAP) {
           /// Codes Added by Arpon:
         /// Arpon's Note: Determining next projectile randomly
         int num = randbw(0,2);
         /// Arpon's Note:Increasing respective projectile count
         if(num == TYPE_COIN) {
           coinsTossed++;
         }
         else if (num == TYPE_BOMB){
           bombsTossed++;
         }
         else if (num == TYPE_SPL_COIN){
           impTossed++;
         }

        /// Arpon's Note: Updating display text
         sprintf(coinTossedStr, "Coins Tossed: %d Bombs Tossed: %d Imp Tossed:%d Lasso Thrown:%d ", coinsTossed,bombsTossed,impTossed,lassoThrown);
         coinTossedText->setMessage(coinTossedStr);


         /// Arpon's Note: Sending projectile type to ptile object.
         ///Arpon's Note: ptile object will change the look of projectile according to this number
         ptile->setType(num);/// Arpon's Note: Informing ptile object about type
         ptile->unpause();
         }
       }

       if(ptile->getYPos() > PLAY_Y_HEIGHT ) {
/// Arpon's Note:Projectile is not captured. hence if it is a special coin we need to reduce from the score
         if(ptile->getType() == TYPE_SPL_COIN) {
           lasso->reduceFromScore(1) ;
         }
        /// Arpon's Note:Resting projectile data for current throw to start for new throw
         ptile->resetProjectile();
         last_coin_jump_end = currTime;
         /// Codes Added by Arpon:

       }
/// Arpon's Note: Updating display text for score
       sprintf(coinScoreStr, "Current Score: %d",lasso->getScore());
       coinScore->setMessage(coinScoreStr);

       /// Codes Added by Arpon:
       sprintf(coinsCollectedStr, "Coins Collected: %d", lasso->getScore());
        coinsCollectedText->setMessage(coinsCollectedStr);

       stepCount++;
       currTime += stepTime;
       wait(stepTime);
     } // End for(;;)


}
