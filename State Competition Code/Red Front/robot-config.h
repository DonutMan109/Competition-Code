using namespace vex;

//var
bool  toggledrive = true;
bool pid = false;

int autoselect;

//declarations of brain, motors, sensors, etc.
vex::brain Brain = vex::brain();
vex::controller Controller1 = vex::controller(vex::controllerType::primary);
vex::controller Controller2 = vex::controller(vex::controllerType::partner);

vex::motor LeftDrive1 = vex::motor(vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::motor LeftDrive2 = vex::motor(vex::PORT4, vex::gearSetting::ratio18_1, false);
vex::motor RightDrive1 = vex::motor(vex::PORT1, vex::gearSetting::ratio18_1, true);
vex::motor RightDrive2 = vex::motor(vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::motor Intake = vex::motor(vex::PORT5, vex::gearSetting::ratio18_1, false);
vex::motor Catapult = vex::motor(vex::PORT6, vex::gearSetting::ratio36_1, false);
vex::motor Lift = vex::motor(vex::PORT7, vex::gearSetting::ratio36_1, false);
vex::motor Flipper = vex::motor(vex::PORT9, vex::gearSetting::ratio36_1, false);

vex::pot Catapot = vex::pot(Brain.ThreeWirePort.A);
vex::pot Flipperpot = vex::pot(Brain.ThreeWirePort.B);



void controls(){
      while (1){
    Controller2.Screen.print("Lift Temp: %f", Lift.temperature(percentUnits::pct));
    Flipper.stop(brakeType::hold);
    Lift.spin(vex::directionType::rev, Controller2.Axis2.value(), vex::velocityUnits::pct);
    Flipper.spin(vex::directionType::rev, Controller2.Axis3.value()/2, vex::velocityUnits::pct);
    if(Controller2.ButtonL2.pressing()) { //All the way down
        while(Flipperpot.value(rotationUnits::deg) < 218) {//Change Value
            Flipper.spin(directionType::fwd, 70, vex::velocityUnits::pct);
            if(toggledrive) {
      LeftDrive1.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      LeftDrive2.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      RightDrive1.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
      RightDrive2.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
  }
  else {
      LeftDrive1.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
      LeftDrive2.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
      RightDrive1.spin(vex::directionType::rev, Controller1.Axis3.value(), vex::velocityUnits::pct);
      RightDrive2.spin(vex::directionType::rev, Controller1.Axis3.value(), vex::velocityUnits::pct);
  }
        }
        Flipper.stop();
    }
    if(Controller2.ButtonR1.pressing()){  //174 up 222 down
        while(Flipperpot.value(rotationUnits::deg) > 170) {//Change Value
            Flipper.spin(directionType::rev, 80, vex::velocityUnits::pct);
        }
        Flipper.stop();
        vex::task::sleep(200);
        while(Flipperpot.value(rotationUnits::deg) < 200){
            Flipper.spin(directionType::fwd, 30, vex::velocityUnits::pct);
        }
        Flipper.stop();
    }
    if(Controller2.ButtonL1.pressing()) { //Mid / Flipped position
        while(Flipperpot.value(rotationUnits::deg) > 98) {//Change Value
            Flipper.spin(directionType::rev, 30, vex::velocityUnits::pct);
            if(toggledrive) {
      LeftDrive1.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      LeftDrive2.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      RightDrive1.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
      RightDrive2.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
  }
  else {
      LeftDrive1.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
      LeftDrive2.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
      RightDrive1.spin(vex::directionType::rev, Controller1.Axis3.value(), vex::velocityUnits::pct);
      RightDrive2.spin(vex::directionType::rev, Controller1.Axis3.value(), vex::velocityUnits::pct);
  }
        }
        Flipper.stop();
    }
    if(Controller2.ButtonB.pressing()) { //All the way up
        while(Flipperpot.value(rotationUnits::deg) > 1) {//Change Value
            Flipper.spin(directionType::rev, 70, vex::velocityUnits::pct);
            if(toggledrive) {
      LeftDrive1.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      LeftDrive2.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      RightDrive1.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
      RightDrive2.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
  }
  else {
      LeftDrive1.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
      LeftDrive2.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
      RightDrive1.spin(vex::directionType::rev, Controller1.Axis3.value(), vex::velocityUnits::pct);
      RightDrive2.spin(vex::directionType::rev, Controller1.Axis3.value(), vex::velocityUnits::pct);
  }
        }
        Flipper.stop();
    }
    if(Controller1.ButtonY.pressing()) {
        Controller1.rumble(".");
        pid = !pid;
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
    if(pid) {
        LeftDrive1.stop(brakeType::hold);
        LeftDrive2.stop(brakeType::hold);
        RightDrive1.stop(brakeType::hold);
        RightDrive2.stop(brakeType::hold);
    }
    else {
        LeftDrive1.stop(brakeType::coast);
        LeftDrive2.stop(brakeType::coast);
        RightDrive1.stop(brakeType::coast);
        RightDrive2.stop(brakeType::coast);
    }
    if(toggledrive) {
      LeftDrive1.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      LeftDrive2.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      RightDrive1.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
      RightDrive2.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
  }
  else {
      LeftDrive1.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
      LeftDrive2.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
      RightDrive1.spin(vex::directionType::rev, Controller1.Axis3.value(), vex::velocityUnits::pct);
      RightDrive2.spin(vex::directionType::rev, Controller1.Axis3.value(), vex::velocityUnits::pct);
  }
     if(Controller1.ButtonR1.pressing()) {
         Intake.spin(directionType::fwd, 60, vex::velocityUnits::pct);
     }
     else if(Controller1.ButtonR2.pressing()) {
         Intake.spin(directionType::rev, 30, vex::velocityUnits::pct);
     }
     else if(Controller2.ButtonR2.pressing()) {
         Intake.spin(directionType::rev, 30, vex::velocityUnits::pct);
     }
     else if(Controller1.ButtonL1.pressing()){
         Intake.spin(directionType::fwd, 25, vex::velocityUnits::pct);
     }
     else {
         Intake.stop();
     }
     if(Controller1.ButtonB.pressing()) {
        Controller1.rumble(".");
        Catapult.spin(directionType::rev, 100, vex::velocityUnits::pct);
        task::sleep(400);
        while(Catapot.value(rotationUnits::deg) > 173.3 ) {
        Catapult.spin(directionType::rev, 100, vex::velocityUnits::pct);
        if(toggledrive) {
      LeftDrive1.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      LeftDrive2.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      RightDrive1.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
      RightDrive2.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
  }
  else {
      LeftDrive1.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
      LeftDrive2.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
      RightDrive1.spin(vex::directionType::rev, Controller1.Axis3.value(), vex::velocityUnits::pct);
      RightDrive2.spin(vex::directionType::rev, Controller1.Axis3.value(), vex::velocityUnits::pct);
  }
        }
            
        Catapult.stop(brakeType::hold);
        Lift.stop();
        Controller1.rumble(".");
        }
      else {
          Catapult.stop(brakeType::hold);
      }
  vex::task::sleep(20);
}
  }


void controlPrint(){
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
    
    while(Controller2.ButtonR2.pressing()){
        Lift.stop(brakeType::hold);
        controls();
    }
}


/*




                                                            A U T O N F U N C T I O N S




*/


void driveStraight(double spin, int speed){
    Flipper.stop(brakeType::hold);
    LeftDrive1.rotateFor(spin, vex::rotationUnits::rev, speed, vex::velocityUnits::pct, false);
    LeftDrive2.rotateFor(spin, vex::rotationUnits::rev, speed, vex::velocityUnits::pct, false);
    RightDrive1.rotateFor(spin,vex::rotationUnits::rev, speed, vex::velocityUnits::pct, false);
    RightDrive2.rotateFor(spin, vex::rotationUnits::rev, speed, vex::velocityUnits::pct, true);
}

void turn(double left, double right, int speed){
    Flipper.stop(brakeType::hold);
    LeftDrive1.rotateFor(left, vex::rotationUnits::rev, speed, vex::velocityUnits::pct, false);
    LeftDrive2.rotateFor(left, vex::rotationUnits::rev, speed, vex::velocityUnits::pct, false);
    RightDrive1.rotateFor(right,vex::rotationUnits::rev, speed, vex::velocityUnits::pct, false);
    RightDrive2.rotateFor(right, vex::rotationUnits::rev, speed, vex::velocityUnits::pct, true);
}

void flipperDown(double potVal){
    while(Flipperpot.value(rotationUnits::deg) < potVal) {   //218 for all the way down
            Flipper.spin(directionType::fwd, 70, vex::velocityUnits::pct);
    }
    Flipper.stop(brakeType::hold);
}

void flipperUp(double potVal){
    while(Flipperpot.value(rotationUnits::deg) > potVal) {  //98 for mid  128 for auton
            Flipper.spin(directionType::rev, 30, vex::velocityUnits::pct);
    }
    Flipper.stop(brakeType::hold);
}

void botFlag(){
    LeftDrive1.rotateFor(0.5, vex::rotationUnits::rev, 30, vex::velocityUnits::pct, false);
    LeftDrive2.rotateFor(0.5, vex::rotationUnits::rev, 30, vex::velocityUnits::pct, true);
}

void angle(double spin){ //.1 for top flag
    LeftDrive1.rotateFor(spin, vex::rotationUnits::rev, 30, vex::velocityUnits::pct, false);
    LeftDrive2.rotateFor(spin, vex::rotationUnits::rev, 30, vex::velocityUnits::pct, true);
}


void shoot(){
    while(Catapot.value(rotationUnits::deg) > 173.3 ) {
    Catapult.spin(directionType::rev, 100, vex::velocityUnits::pct);
    }
    Catapult.stop(brakeType::hold);
    task::sleep(100);
    Intake.spin(directionType::fwd, 45, vex::velocityUnits::pct);
    task::sleep(200);
    Intake.stop();
    Catapult.spin(directionType::rev, 100, vex::velocityUnits::pct);
    task::sleep(600);
    while(Catapot.value(rotationUnits::deg) > 173.3 ) {
    Catapult.spin(directionType::rev, 100, vex::velocityUnits::pct);
    }
    Catapult.stop(brakeType::hold);
}
