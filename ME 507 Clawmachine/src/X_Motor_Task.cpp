/** @file X_Motor_Task.cpp
 *    This file contains code to test a class for using encoders on STM32's in
 *    the Arduino environment.
 *
 *  @author Michael Yiu
 *  @date   2021-Dec-01
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <STM32FreeRTOS.h>

#include "shares.h"
#include "motor_driver.h"
#include "encoder_counter.h"
#include "X_Motor_Task.h"

extern Share<uint16_t> share_encoder_positionx;
extern Share<uint16_t> share_user_positionx;

void task_x_motor(void *p_params)
{
  // Pointers to timer/counters used; could be in a task function
  Serial << "Initializing X motor and encoder...";
  MotorDriver X_motor(PA0, PA1, PB3);
  STM32Encoder X_encoder(TIM3, PB4, PB5);
  Serial << "done." << endl;

  // delay(1500);
  X_motor.enable();

  // int8_t power = 100;

  // X_motor.setduty(power);
  X_motor.setduty(100); // turn on at max

  for (;;)
  {
    delay(1000);
    Serial << "My X position is: " << X_encoder.getCount() << endl;
    // if (X_encoder.getCount() >= 5000) // spin til encoder 65,535
    // {
    //   X_motor.setduty(-power); // X_motor.disable();
    // }
    // if (X_encoder.getCount() <= 500) // spin til encoder 65,535
    // {
    //   X_motor.setduty(power); // X_motor.disable();
    // }
    
    // if (X_encoder.getCount() < share_user_positionx.get())
    // {
    // }
    // else if (X_encoder.getCount() > share_user_positionx.get())
    // {
    //   X_motor.setduty(-100);
    // }
    // else
    // {
    //   X_motor.setduty(0);
    // }
  }
}