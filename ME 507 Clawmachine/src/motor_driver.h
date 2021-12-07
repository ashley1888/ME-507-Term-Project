/** @file motor_driver.h
 *    This file contains the header for the motor driver class that has methods to enable, disable, and
 *    set the duty cycle of a motor as well as fault detection.
 * 
 *  @author Ashley Humpal and Michael Yiu 
 *  @date   2021-Dec-06 
 */

#include <Arduino.h>
#include <PrintStream.h>

/** @brief   Class which implements a motor driver.
 *  @details Contains methods to enable, disable, and set duty of motor.
 * 
 */
class MotorDriver
{
protected:

   /// Variable representing the nsleep pin for power
   uint8_t _nsleep;
   /// Variable representing the nfault pin
   uint8_t _nfault;
   /// Variable representing the the pin for the positive motor lead
   uint8_t _pin1;
   // Variable representing the the pin for the negative motor lead
   uint8_t _pin2;
public:
   // Constructor which takes in multiple pins as parameters
   MotorDriver (uint8_t pin1, uint8_t pin2, uint8_t nsleep, uint8_t nfault );
   void enable (void); // turn on motor
   void faulted (void); // fault detection
   void disable (void); // disable motor 
   void setduty (int8_t duty); // set motor duty 
};