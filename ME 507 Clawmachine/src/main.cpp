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
// #include "taskshare.h"
// #include "shares.h"
#include "X_Motor_Task.h"
#include "Y_Motor_Task.h"

// Share<uint16_t> share_encoder_positionx; 
// Share<uint16_t> share_encoder_positiony;
// Share<uint16_t> share_user_positionx;
// Share<uint16_t> share_user_positiony;
// Share<uint16_t> share_job_status;

/** @brief   Arduino setup function which runs once at program startup.
 *  @details This function sets up a serial port for communication and creates the
 *           tasks which will be run.
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  delay (1500);

  xTaskCreate (task_x_motor,     // Task function
              "X_Motor",             // Name in diagnostic printouts
              1000,                   // Stack size in bytes
              NULL,                   // Parameters for task function
              5,                      // Task priority
              NULL);                  // Handle to task struct
  xTaskCreate (task_y_motor,     // Task function
              "Y_Motor",             // Name in diagnostic printouts
              1000,                   // Stack size in bytes
              NULL,                   // Parameters for task function
              5,                      // Task priority
              NULL);                  // Handle to task struct

    // STM32duino requires that the FreeRTOS scheduler be manually started
    vTaskStartScheduler ();

  //MotorDriver object1( 24, 23, 70) ;
  // MotorDriver object1( PB10, PC7, PB3) ;
  // object1.enable();
  // object1.setduty(0);
  // delay(10000);
  // object1.disable();


  // uint16_t currentjobstatus;
  // // share_job_status.get(currentjobstatus);
  
  // uint16_t one = 1;
  // if (currentjobstatus == one )
  // {
  //  Serial.println("Item has been picked and dropped.");

  // }

}
void loop() {
}