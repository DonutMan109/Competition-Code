#include "robot-config.h"
#include <iostream>
#include <string>

vex::competition Competition;


void pre_auton( void ) {
}

void autonomous( void ) {
    LeftDrive1.stop();
    LeftDrive2.stop();
    RightDrive1.stop();
    RightDrive2.stop();
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


