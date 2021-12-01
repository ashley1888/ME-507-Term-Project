/** @file motor1_task.cpp
 *    This file contains code to test a class for using encoders on STM32's in
 *    the Arduino environment.
 * 
 *
 *  @author JR Ridgely
 *  @date   2020-Nov-15 Original file, based on stuff from the Interwebs

 */

#include <Arduino.h>
#include <PrintStream.h>
#include <STM32FreeRTOS.h>

// #include "shares.h"
#include "motor_driver.h"
#include "encoder_counter.h"
#include "X_Motor_Task.h"

void task_x_motor (void* p_params)
{
    // Pointers to timer/counters used; could be in a task function
    Serial << "Initializing X motor and encoder...";
    MotorDriver X_motor(PA0, PA1, PB3);
    STM32Encoder X_encoder(TIM3, PB4, PB5);
    Serial << "done." << endl;

    delay(1500);
    X_motor.enable();

    int8_t power = 100;
    
    X_motor.setduty(power); //turn on at max

    for (;;){
        delay (500);

        Serial << "My X position is: " << X_encoder.getCount() << endl;        

        if (X_encoder.getCount() >= 5000){ // spin til encoder 65,535

          X_motor.setduty(-power);
          // X_motor.disable();
        }
        if (X_encoder.getCount() <= 500){ // spin til encoder 65,535

          X_motor.setduty(power);
          // X_motor.disable();
        }
    }
}