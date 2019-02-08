#include "robot-config.h"
#include <iostream>
#include <string>

vex::competition Competition;


void pre_auton( void ) {
}

void autonomous( void ) {
    
    /*                          DONT MAKE NEGATIVE VALUES POSITIVE UNLESS I FUCKED UP AND IT TURNS / GOES THE WRONG DIRECTION (which is actually pretty likely...)   */
    
    //line up the same way as front red tile, but have the intake facing the flags
    driveStraight(1.35, 70);    //drives forward a tile
    turn(1, -1, 50);            //90 degrees right. if turn isn't enough, increase both 1's by a decimal. if it turns too much decrease by decimal. keep the 50
    flipperDown(218);  //the 218 is the pot value it will go to
    driveStraight(2.3, 60);  //should position the flipper to be just under the cap. Too much: lower 2.3  too little: increase 2.3, keep 60
    flip();                     
    vex::task::sleep(300);          //flip() to unflip() flips the cap. same as jd's flip button, just separated into functions so don't worry about values
    unflip();
    
    //so im adding stuff i guess? theoretically this would knock that tilted cap but idk man. if you can't get it to work just delete it lmao
    /*      get rid of the multi line comments if you wanna run it :)
    driveStraight(-1.35, 60);  //drives back a tile. only change the 1.35
    turn(1, -1, 50);        //90 degress right. intake should face wall? if needed, change the 1's.
    driveStraight(1.35, 60);   //should go to the tile right before the tilted cap
    turn(1, -1, 50);    //another 90 degree right. this is probably gonna have to be fine tuned by decimal points, so change the 1's
    driveStraight(-1, 50);     //should knock the cap? just mess around with the 1 to get it right, not the 50
    */
}




void usercontrol( void ) {
  controlPrint();
  controls();  
}




int main() {
    pre_auton();

    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    while(1) {
      if(Controller1.ButtonX.pressing()) {
          Controller1.rumble(".");
          toggledrive = !toggledrive;
          if(pid) {
          if(toggledrive) {
          Controller1.Screen.print("   PID Tank   ");
          Controller2.Screen.print("   PID Tank   ");
          }
           else{
          Controller1.Screen.print("  PID Rev-Tank");
          Controller2.Screen.print("  PID Rev-Tank");
           }  
          }
          else {
          if(toggledrive) {
          Controller1.Screen.print("       Tank   ");
          Controller2.Screen.print("       Tank   ");
          }
           else{
          Controller1.Screen.print("   Rev-Tank   ");
          Controller2.Screen.print("   Rev-Tank   ");
           }  
          }
      }
      vex::task::sleep(100);
    }    
       
}


