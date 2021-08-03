# CS101LassoGame_1stSem
Contained here are the codes I used for making a "lasso game" as part of my project in the CS101 course. This uses the graphics software "simplecpp", installation instructions of which have also been added in simplecpp.zip.
The zip file is if you want to download my code without forking/cloning the repo, the folder is if you just wanna view the code.

Link for the video (for visual explanation) is given below:

https://drive.google.com/file/d/1xqcS50Y_7YqbAiJz15DwWoXDpEUhjFRv/view?usp=sharing


General Readme (Made as part of project)

This program is enhancement of the original lasso program by Arpon Basu.

Game Enhancements Carried Out
===========================
1) Game now has three levels 0, 1 and 2.
2) Apart from coins, bombs and special coins are also thrown.
   a) If a bomb is collected a point will be deducted.
   b) If a special coin is collected then one point will be added and if
      it is not collected a point will be deducted.
3) In level 1, coin, bomb or special coin will be randomly fired at an angle
   between 85 to 95 degree.
4) In level 2, coin, bomb or special coin will be randomly fired at an angle
   between 85 to 95 degree with a variable muzzle speed.This makes the level 2
   harder than level 0 and 1.
5) A level will end once lasso is thrown five times.
6) An welcome screen is added before the game start where player Will
   be able to choose the level she wants to play.
7) Throughout the game in every level score, level number, state of the game (running or paused)
   ,coins,bombs,special coin and lasso count is displayed in the canvas itself.
8) End of level is displayed with a blinking message.
9) Two additional key press detection is added. Pressing 'h' will launch
   a help document in the terminal as well as open a pdf of the same in Google Chrome.
    and pressing 'q' will quit the game with a message.
10) A comprehensive help file is added for the player to get help.


Code Changes Carried Out
===========================

1) Various different types of "actions" are broken down into different
   small logical pieces and implemented inside a method or function.
   This improved code readability and bug testing.
2) Additional features described in the Game Enhancement section
   have been implemented.
3) As code is divided into different functional units, many
   declaration variables need to be global in scope. To ensure
   that a main.h file is created, variables are defined there
   so that it become global in scope for main.cpp. main.h
   is included in main.cpp.
4) Original Lasso game had Coin class. Here Coin class is replaced
   by Projectile class which greatly extends the original Coin class.
   An object of the projectile class can now be changed to a bomb or
   a special coin.
5) Few additional methods and functions have been implemented in the lasso class.
6) Projectile Class and Lasso Class header as well as cpp file is extensively commented 
   to better understand the code as well as the logic.

