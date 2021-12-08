/** @file mainpage.cpp
 *    
 *  @mainpage
 * 
 *  @section page_intro Introduction
 * 
 *  This website contains all relevant software information concerning our ME 507 Term project the Claw Machine.
 *  At a high level what occurs in our project is that the controller task reads the user’s input position and sends that location to the x and y-motor tasks.
 *  After reading the position, the two x and y-motors actuate and continue to rotate until the encoder indicates that they have reached the correct position, 
 *  to a certain allowable tolerance. Once the correct x and y-positions have been reached, the z-motor activates for a predetermined length of time, descending the gripper. 
 *  When the end effector reaches its destination, the gripper-motor actuates for a different predetermined length of time to close and grasps the object.
 * 
 *  The encoder driver files were supplied by our professor, Dr. Ridgely and their source code can be found at: 
 *  @c https://github.com/spluttflob/ME507-Support/blob/master/examples/encoder_counter.cpp
 *  @c https://github.com/spluttflob/ME507-Support/blob/master/examples/encoder_counter.h
 * 
 *  @author Ashley Humpal and Michael Yiu
 *  @date 2021-01-Dec
 * 
 *  @page page_diagrams Task Diagram
 *  @section sec_diagram Task Diagram
 *  Below is an image of the task diagram used for this project
 *  @image html hw0statediagram.jpg "Figure 1: Claw Machine Task Diagram" width=75%
 * 
 *  @page page_control Controller Task
 *  @section sec_control Controller Task
 *    This file is the controller task of the claw machine. 
 *    It has the user enter a value between 1 and 64, where
 *    each value represents a position on an 8x8 chessboard.
 *    Once a value has been entered, the controller task sends
 *    the responding x and y-values to the x and y-motors. The
 *    purpose of the value is so that the motor encoders know
 *    when they have reached their destination.
 *    It's source code can be found at: 
 * 
 *    @c https://github.com/ashley1888/ME-507-Term-Project/blob/main/ME%20507%20Clawmachine/src/controller_task.cpp
 * 
 *  @page page_motor Motor Tasks
 *  @section sec_x X-Motor Task
*     This file contains the implementation of the x-motor task.
 *    It waits for the user to give it a refernce position value,
 *    which is obtained from the controller task. Once a value has
 *    been obtained, the motor powers on and only turns off once the
 *    encoder is within 50 ticks of the destination.
 *    It's source code can be found at: 
 * 
 *    @c https://github.com/ashley1888/ME-507-Term-Project/blob/main/ME%20507%20Clawmachine/src/X_Motor_Task.cpp
 *  @section sec_y Y-Motor Task
 *    This file contains the implementation of the y-motor task.
 *    It waits for the user to give it a refernce position value,
 *    which is obtained from the controller task. Once a value has
 *    been obtained, the motor powers on and only turns off once the
 *    encoder is within 50 ticks of the destination.
 *    It's source code can be found at: 
 * 
 *    @c https://github.com/ashley1888/ME-507-Term-Project/blob/main/ME%20507%20Clawmachine/src/Y_Motor_Task.cpp
 *  @section sec_z Z-Motor Task
 *    This file contains the implementation of the z-motor task. 
 *    It turns only runs once the x and y-tasks have indicated that
 *    they have been completed. The z-motors will turn off once the
 *    specific length of time has elapsed.
 *    It's source code can be found at: 
 * 
 *    @c https://github.com/ashley1888/ME-507-Term-Project/blob/main/ME%20507%20Clawmachine/src/Z_Motor_Task.cpp
 *  @section sec_gripper Gripper-Motor Task
 *    This file contains the implementation of the gripper-motor task. 
 *    It turns only runs once the z-tasks has indicated that
 *    it has completed. The gripper-motors will turn on for a
 *    specified length of time to grasp an object, then wait a
 *    different specified length of time before releasing it.
 *    It's source code can be found at: 
 * 
 *    @c https://github.com/ashley1888/ME-507-Term-Project/blob/main/ME%20507%20Clawmachine/src/Gripper_Motor_Task.cpp
*/