/** @file main.cpp
 *    This file contains a simple test program with which C++ for the STM32 using 
 *    Arduino is tested along with various other tools such as Doxygen and Git.
 *
 *  @author Ashley Humpal
 *  @date 2021-19-Oct 
 
 */
#include <Arduino.h>
#include <PrintStream.h>
#include <motor_driver.h>

#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include "taskshare.h"
#include "shares.h"
#include "controller_task.h"

Share<uint16_t> share_encoder_positionx; 
Share<uint16_t> share_encoder_positiony;
Share<uint16_t> share_user_positionx;
Share<uint16_t> share_user_positiony;
Share<uint16_t> share_job_status;


/** @brief   Arduino setup function which runs once at program startup.
 *  @details This function sets up a serial port for communication and creates the
 *           tasks which will be run.
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  delay (6000);

  xTaskCreate (task_control     // Task function
                 "Control",             // Name in diagnostic printouts
                 1000,                   // Stack size in bytes
                 NULL,                   // Parameters for task function
                 8,                      // Task priority
                 NULL);                  // Handle to task struct

    // STM32duino requires that the FreeRTOS scheduler be manually started
    vTaskStartScheduler ();

  //MotorDriver object1( 24, 23, 70) ;
  MotorDriver object1( PB10, PC7, PB3) ;
  object1.enable();
  object1.setduty(0);
  delay(10000);
  object1.disable();


  uint16_t currentjobstatus;
  share_job_status.get(currentjobstatus);
  
  uint16_t one = 1;
  if (currentjobstatus == one )
  {
   Serial.println("Item has been picked and dropped.");

  }


// need to add the other tasks, and make this iterate


  //object1.set_duty( high or low or duty level? );
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print ("  .  ");
    delay (6000);
}