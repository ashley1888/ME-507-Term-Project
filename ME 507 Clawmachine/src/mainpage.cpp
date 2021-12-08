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
 * @c https://github.com/spluttflob/ME507-Support/blob/master/examples/encoder_counter.cpp
 * @c https://github.com/spluttflob/ME507-Support/blob/master/examples/encoder_counter.h
 * 
 *  @author Ashley Humpal and Michael Yiu
 *  @date 2021-01-Dec
*/