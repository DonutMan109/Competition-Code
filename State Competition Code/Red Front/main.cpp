#include "robot-config.h"
#include <iostream>
#include <string>

vex::competition Competition;


void pre_auton( void ) {
}

void autonomous( void ) {
    driveStraight(-0.5, 50);  //back into expansion
    vex::task::sleep(100);
    flipperDown(120); //claw mid
    driveStraight(1.5, 60); //line up for top flag
    vex::task::sleep(500);
    angle(.1);
    shoot();
    angle(-.1);  //shoot top flag
    driveStraight(-.5, 50);  //back to center in red tile
    turn(1, -1, 60);  //90 right
    driveStraight(1, 50);
    turn(-1.95, 1.95, 60);
    Intake.spin(directionType::fwd, 45, vex::velocityUnits::pct);
    driveStraight(-2.3, 80);
    vex::task::sleep(900);
    Intake.stop(brakeType::coast);
    driveStraight(2, 70);
    turn(.5, -.5, 50);
    driveStraight(1.5, 50);
    turn(.55, -.55, 50);
    driveStraight(1.7, 60);
    angle(.4);
    shoot();
    driveStraight(-1, 50);
    Flipper.stop(brakeType::coast);
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


