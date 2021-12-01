/** @file motor_driver.h
 *  This file 
 * 
 *  @author Michael Yiu
 *  @date   2021-Dec-01
 */

#include <Arduino.h>
#include <PrintStream.h>

/** @brief   Class
 *  @details This
 * 
 */
class MotorDriver
{
protected:
   // The number of points in the data set
   uint32_t pinstatus;
   uint8_t _nsleep;
   uint8_t _pin1;
   uint8_t _pin2;
public:
   MotorDriver (uint8_t pin1, uint8_t pin2, uint8_t nsleep);
   void enable (void);
   void disable (void);
   void setduty (int8_t duty); // Constructor 
};