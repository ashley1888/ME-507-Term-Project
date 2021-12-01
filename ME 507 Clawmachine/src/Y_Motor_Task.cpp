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
#include "Y_Motor_Task.h"

void task_y_motor (void* p_params)
{
    // Pointers to timer/counters used; could be in a task function
    Serial << "Initializing Y motor and encoder...";
    MotorDriver Y_motor(PB10, PC7, PB3);
    STM32Encoder Y_encoder(TIM1, PA8, PA9);
    Serial << "done." << endl;

    delay(1500);
    Y_motor.enable();

    int8_t power = 100;

    Y_motor.setduty(power); //turn on at max

    for (;;){
        delay (500);

        Serial << "My Y position is: " << Y_encoder.getCount() << endl;        

        if (Y_encoder.getCount() >= 5000){ // spin til encoder 65,535

          Y_motor.setduty(-power);
          // Y_motor.disable();
        }
        if (Y_encoder.getCount() <= 500){ // spin til encoder 65,535

          Y_motor.setduty(power);
          // Y_motor.disable();
        }
    }
}