/** @file main.cpp
 *    This file contains a simple test program with which C++ for the STM32 using 
 *    Arduino is tested along with various other tools such as Doxygen and Git.
 *
 *  @author Ashley Humpal
 *  @date 2021-19-Oct 
 
 */
#include <Arduino.h>
#include <PrintStream.h>


#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include "taskshare.h"
#include "shares.h"
#include "controller_task.h"
//#include "controllery_task.h"
#include "motor1_task.h"
#include "motor2_task.h"

Share<uint16_t> share_encoder_positionx; 
Share<uint16_t> share_encoder_positiony;
Share<uint16_t> share_user_positionx;
Share<uint16_t> share_user_positiony;
Share<uint16_t> share_job_status;

Queue<uint16_t> queue_userx (1, "Inputs");
Queue<uint16_t> queue_usery (1, "Inputsy");


/** @brief   Arduino setup function which runs once at program startup.
 *  @details This function sets up a serial port for communication and creates the
 *           tasks which will be run.
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  delay (4000);
  Serial.print ("  Input the x location: ");
  //delay (2000);
  //Serial.print ("  Input the y location: ");


  xTaskCreate (task_control,     // Task function
                 "Control",             // Name in diagnostic printouts
                 1000,                   // Stack size in bytes
                 NULL,                   // Parameters for task function
                 1,                      // Task priority
                 NULL);                  // Handle to task struct

    // STM32duino requires that the FreeRTOS scheduler be manually started
    //vTaskStartScheduler ();
// xTaskCreate (task_controly,     // Task function
//                  "Controly",             // Name in diagnostic printouts
//                  1000,                   // Stack size in bytes
//                  NULL,                   // Parameters for task function
//                  2,                      // Task priority
//                  NULL);                  // Handle to task struct

//     // STM32duino requires that the FreeRTOS scheduler be manually started
//     //vTaskStartScheduler ();
  
// Create the task that tests the encoder interface class
    xTaskCreate (task_move_motor ,     // Task function
                 "Motorx",             // Name in diagnostic printouts
                 1000,                   // Stack size in bytes
                 NULL,                   // Parameters for task function
                 3,                      // Task priority
                 NULL);                  // Handle to task struct

xTaskCreate (task_move_motor2 ,     // Task function
                 "Motory",             // Name in diagnostic printouts
                 1000,                   // Stack size in bytes
                 NULL,                   // Parameters for task function
                 2,                      // Task priority
                 NULL);                  // Handle to task struct

    // STM32duino requires that the FreeRTOS scheduler be manually started
    //vTaskStartScheduler ();
    #if (defined STM32L4xx || defined STM32F4xx)
        vTaskStartScheduler ();
    #endif
  // uint16_t currentjobstatus;
  // share_job_status.get(currentjobstatus);
  
  // uint16_t one = 1;
  // if (currentjobstatus == one )
  // {
  //  Serial.println("Item has been picked and dropped.");

  // }

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print ("  .  ");
    delay (6000);
}