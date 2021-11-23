/** @file motor_driver.h
 *    This file 
 * 
 * 
 * 
 *  @author Ashley Humpal
 *  @date  2021-Nov-16
 */



/** @brief   Class
 *  @details This
 * 
 * 
 */

#include <Arduino.h>
class MotorDriver
{
protected:
    /// The number of points in the data set
    uint32_t pinstatus;
    uint8_t _nsleep;
    uint8_t _pin1;
    uint8_t _pin2;
    
    
 
 public:
   MotorDriver::MotorDriver (uint8_t pin1, uint8_t pin2, uint8_t nsleep );
   void enable (void);
   void disable (void);
   void setduty (uint8_t duty); // Constructor 
};