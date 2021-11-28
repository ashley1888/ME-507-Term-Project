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
#include "taskshare.h"


Share<uint16_t> share_encoder_positionx; 
Share<uint16_t> share_encoder_positiony;
Share<uint16_t> share_user_positionx;
Share<uint16_t> share_user_positiony


/** @brief   Arduino setup function which runs once at program startup.
 *  @details This function sets up a serial port for communication and creates the
 *           tasks which will be run.
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  delay (6000);
  //MotorDriver object1( 24, 23, 70) ;
  MotorDriver object1( PB10, PC7, PB3) ;
  object1.enable();
  object1.setduty(0);
  delay(5000);
  object1.disable();




  //object1.set_duty( high or low or duty level? );
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print ("  .  ");
    delay (6000);
}