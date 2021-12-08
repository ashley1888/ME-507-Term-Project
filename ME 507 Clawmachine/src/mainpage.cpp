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
 *  The encoder driver file was supplied by our professor, Dr. Ridgely and its documentation can be found at: 
 * 
 *  @author Ashley Humpal and Michael Yiu
 *  @date 2021-01-Dec
 * 
 *  @page page_diagrams Task Diagram
 *  @section sec_diagram Task Diagram
 *  Below is an image of the task diagram used for this project
 *  @image html hw0statediagram.jpg "Figure 1: Claw Machine Task Diagram" width=75%
 * 
 *  @page page_code Motor Tasks
 *  @section sec_x X-Motor Task
*     This file contains the implementation of the x-motor task.
 *    It waits for the user to give it a refernce position value,
 *    which is obtained from the controller task. Once a value has
 *    been obtained, the motor powers on and only turns off once the
 *    encoder is within 50 ticks of the destination.
 *    It's source code can be found at: 
 * 
 *    (replace with source code url)
 *  @section sec_y Y-Motor Task
 *    This file contains the implementation of the y-motor task.
 *    It waits for the user to give it a refernce position value,
 *    which is obtained from the controller task. Once a value has
 *    been obtained, the motor powers on and only turns off once the
 *    encoder is within 50 ticks of the destination.
 *    It's source code can be found at: 
 * 
 *    (replace with source code url)
 *  @section sec_z Z-Motor Task
 *    This file contains the implementation of the z-motor task. 
 *    It turns only runs once the x and y-tasks have indicated that
 *    they have been completed. The z-motors will turn off once the
 *    specific length of time has elapsed.
 *    It's source code can be found at: 
 * 
 *    (replace with source code url)
 *  @section sec_gripper Gripper-Motor Task
 *    This file contains the implementation of the gripper-motor task. 
 *    It turns only runs once the z-tasks has indicated that
 *    it has completed. The gripper-motors will turn on for a
 *    specified length of time to grasp an object, then wait a
 *    different specified length of time before releasing it.
 *    It's source code can be found at: 
 * 
 *    (replace with source code url)
*/