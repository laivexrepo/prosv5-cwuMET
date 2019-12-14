#include "main.h"
#include "globals.h"
#include "portdef.h"
#include "claw.h"

void clawControl(){
  // you could make clawCOntrol also take an input varibale for speed,
  // perhaps an speedOpen and a speedClose
  if (master.get_digital(DIGITAL_L1)) {
     clawMotor.move_velocity(50);
   }
   else if (master.get_digital(DIGITAL_L2)) {
     clawMotor.move_velocity(-50);
   }
   else {
     clawMotor.move_velocity(0);
   }
}
