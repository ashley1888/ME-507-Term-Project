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

// void task_move_motor (void* p_params)
// {
//     uint16_t usergivenx;
//     share_user_positionx.get(usergivenx);

//     uint16_t currentencoderx;
//     share_encoder_positionx.get(currentencoderx);

    
    

//     if (usergivenx != currentencoderx) // if the current encoder position isnt equal to the user desired than do the following
//     //when making other motor task use shares for y since that is for the other encoder
//     {
//      object1.setduty(35); // keep moving

//     }
// // error below
//     else 
//     { object1.setduty(0); // stop
//       delay (power0); // wait
//       object1.setduty(-35); // reverse direction
//       if (currentencoderx!= 0)// want to keep reversing direction until encoders at origin position again 
//         {
//           object1.setduty(-35);
//         }
//       else
//         {
//          object1.setduty(0); 
//          uint8_t jobstatus = 1; // job is complete
         
//          share_job_status.put(jobstatus); // put number 1 into share variable to send to main

//          }
     
//       //  it checks if its returned to its orgin

//     // then sends the share bool that the job is completed 
//      }

//  }

    
//     // set up code goes here
// // check encoder val, if correct spot stop spinning otherwise continue setduty funct
// // set up shares to get encoder values 

//     for (;;)
//     {
//         delay (power);

        
//     }
// }


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