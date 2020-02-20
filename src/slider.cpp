#include "main.h"
#include "globals.h"
#include "portdef.h"
#include "slider.h"

float maxSliderMovement = 540;       // Maximum rotations slider can move 540 = 1.5 rotations

int sliderGearRatio = 1;            // gear ratio between motor and slider
                                    // if a 12gear drives a 84gear the ratio is 84/12 = 7
                                    // for direct drive it is 1

void sliderControl(int speedUp, int speedDown){
  if (master.get_digital(DIGITAL_UP)) {
     sliderMotor.move_velocity(speedUp);
   }
   else if (master.get_digital(DIGITAL_DOWN)) {
     sliderMotor.move_velocity(-speedDown);
   }
   else {
     sliderMotor.move_velocity(0);
   }
}

void sliderMoveForRotation(float degrees, int speed ){
  // moves the lift to a given position based on angle provided, it returns the
  // angle of the lift where it has stopped
  if(DEBUG) { std::cout << "Requested rotation: " << degrees << " speed: " << speed << "\n";}
  if(DEBUG) { std::cout << "Gear Ratio: " << sliderGearRatio << " New rotaiton: " << degrees * sliderGearRatio << "\n"; }

  degrees = sliderGearRatio * degrees;            // account for gear Ratio

  // get current angle of the lift.
  float currentDegrees = sliderMotor.get_position();

  if(degrees < 0) {
    if(DEBUG) { std::cout << "Can not move down past ZERO position \n"; }
  } else {
    if(degrees > (maxSliderMovement * sliderGearRatio) ) {
      // We need to accomedate gear ratio in calculation the true angle is adjusted
      // by liftGearRatio for the actual motor move angle.
      if(DEBUG) { std::cout << "Can not move past maximum rotation of:" << maxSliderMovement << " \n"; }
    } else {
      // we can move so lets....
      // calculate the target window
      float minDegrees = degrees - 5;
      float maxDegrees = degrees + 5;
      if(DEBUG) { std::cout << "Rotation: " << degrees << " minRotation: " << minDegrees << " maxRotation: " << maxDegrees << "\n";}
      sliderMotor.move_absolute(degrees, speed);

      while (!((sliderMotor.get_position() < maxDegrees) && (sliderMotor.get_position() > minDegrees))) {
        pros::delay(2);
      }
    }
    sliderMotor.move_velocity(0);
  }
  if(DEBUG) { std::cout << "Final Rotation: " << sliderMotor.get_position() << " True rotation: " << (sliderMotor.get_position() / sliderGearRatio) << " \n"; }
}
