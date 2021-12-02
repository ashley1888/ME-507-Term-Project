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

#include "shares.h"



/** @brief   Task which tests the reading of encoders using the @c STM32Encoder
 *           class.
 *  @param   p_params A pointer, which is ignored, to no parameters
 */


 //not the correct pins -- also not sure whether the object should be created in main instead

void task_move_motor (void* p_params)
{
    uint16_t usergivenx;
   // uint16_t usergiveny;
    

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
//       delay (1000); // wait
//       object1.setduty(-35); // reverse direction
//       if (currentencoderx!= 0)// want to keep reversing direction until encoders at origin position again 
//         {
//           object1.setduty(-35);
//         }
//       else
//         {
//          object1.setduty(0); 
//          uint16_t jobstatus = 1; // job is complete
//          share_job_status.put(jobstatus); // put number 1 into share variable to send to main
//          }
//       //  it checks if its returned to its orgin
//     // then sends the share bool that the job is completed 
//      }
//  }

    for (;;)
    {
      delay (8000);  
      uint16_t zero = 0; 
    
      //share_user_positionx.get(usergivenx);
      queue_userx.get(usergivenx);

      delay(5000);
      //Serial.print (usergivenx);

      //if (usergivenx != 0)
      //{
      
      Serial.print ("  The shares variable value for x is ");
      //Serial.print (usergivenx); 
      //char usergivenxx = usergivenx;
      Serial.print(usergivenx);

      // Serial.print ("  The shares variable value for y is ");
      // //Serial.print (usergivenx); 
      // char usergivenyy = usergiveny;
      // Serial.print(usergivenyy);
      //}

    }
}




    
