#ifndef CLAW_H_
#define CLAW_H_

extern float maxAngleClawOpen;
extern int clawGearRatio;

void clawControl();

void clawSetLowPreset();

float clawOpenForAngle(float angle, int speed );

#endif
