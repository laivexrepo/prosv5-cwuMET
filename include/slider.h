#ifndef SLIDER_H_
#define SLIDER_H_

void sliderControl(int speedUp, int speedDown);
void sliderSetLowPreset();

void sliderMoveForRotation(float degrees, int speed );

extern float maxSliderMovement;       // maximum amount of rotation the slider can move
extern int sliderGearRatio;           // not use likely but setting to = 1 is
                                      // same as not having a gear ratio

#endif
