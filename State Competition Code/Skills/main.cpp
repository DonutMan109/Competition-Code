#include "robot-config.h"
#include <iostream>
#include <string>

vex::competition Competition;


void pre_auton( void ) {
}

void autonomous( void ) {
    driveStraight(-0.5, 50);  //back into expansion
    vex::task::sleep(100);
    flipperDown(128); //claw mid
    driveStraight(3.3, 80); //hit bot flag, lessen the 3.3 if it goes too far. that mean's you'll have to change the next driveStraight()
    angle(.4); //angle to shoot. change by decimals only
    shoot();
    angle(-.4);  //straighten bot. number should match first angle() but negative
    driveStraight(-2.36, 100); //back into red. change this depending on how you changed the other one. keep 100 tho
    turn(1.2, -1.2, 60);  //90 right. intake should be facing wall. if needed, change 1.2 but I think it's easier to change the next turn() 
    driveStraight(1, 50);       //move forward a bit so flipper doesn't hit wall for the next turn
    turn(-2, 2, 60);   //should turn so that the intake faces the tilted cap. increase the 2's if it doesn't turn enough, decrease if it's too much. i would only change by decimals tho
    Intake.spin(directionType::fwd, 45, vex::velocityUnits::pct);
    driveStraight(-2.3, 80);   //intake ball and knock cap. if ball doesn't intake, mess with the previous turn()
    vex::task::sleep(500);
    Intake.stop(brakeType::coast);
    turn(1, -1, 40); //90 right turn towards middle flag pole
    
    //this part is different cuz i want to hit the top flag instead of mid. if it doesn't work, delete and use the commented one instead.
    driveStraight(.5, 50);      //this might not even be neccessary, i just don't know where you have to be to shoot. change the .5 value to whatever in order to line it up
    angle(.1); //angle to shoot. i pulled the value from the amount needed to hit the top flag in red front, but it might be different here?
    shoot();
    angle(-.1);  //straighten bot
    driveStraight(2.7, 80); //hit bot flag. only change the 2.7 depending on if it goes too far or not
    driveStraight(-1, 80);  //back away from the flag a bit
    Flipper.stop(brakeType::coast);
    
    /*
    driveStraight(2.7, 80); //hit bot flag. change 2.7 to something slightly lower if it goes too far
    angle(.4); //angle to shoot. decrease decimal if it turns too much, vice versa. d o n t   g o   a b o v e   o n e
    shoot();
    angle(.4);  //straighten bot. value should match previous angle()
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




