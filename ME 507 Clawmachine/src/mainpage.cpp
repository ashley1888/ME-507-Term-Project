/** @file mainpage.cpp
 *    
 *  @mainpage
 * 
 *  @section page_intro Introduction
 * 
 *  @image html isometric_view.png "Claw Machine Isometric View" width=75%
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
 *  @page page_diagram Task Diagram
 *  @section sec_diagram Task Diagram
 *  Below is an image of the task diagram used for this project
 *  @image html taskdiagram.png "Figure 1: Claw Machine Task Diagram" width=75%
 * 
 *  @page page_control Controller Task
 *  @section sec_control Controller Task
 *    This task is the controller task of the claw machine. 
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
 *    This task for the user to give it a reference x-position value,
 *    which is obtained from the controller task. Once a value has
 *    been obtained, the motor powers on and only turns off once the
 *    encoder is within 50 ticks of the destination.
 *    It's source code can be found at: 
 * 
 *    @c https://github.com/ashley1888/ME-507-Term-Project/blob/main/ME%20507%20Clawmachine/src/X_Motor_Task.cpp
 *  @section sec_y Y-Motor Task
 *    This task waits for the user to give it a refernce y-position value,
 *    which is obtained from the controller task. Once a value has
 *    been obtained, the motor powers on and only turns off once the
 *    encoder is within 50 ticks of the destination.
 *    It's source code can be found at: 
 * 
 *    @c https://github.com/ashley1888/ME-507-Term-Project/blob/main/ME%20507%20Clawmachine/src/Y_Motor_Task.cpp
 *  @section sec_z Z-Motor Task
 *    This task only runs once the x and y-tasks have indicated that
 *    they have been completed. The z-motors will turn off once the
 *    specific length of time has elapsed.
 *    It's source code can be found at: 
 * 
 *    @c https://github.com/ashley1888/ME-507-Term-Project/blob/main/ME%20507%20Clawmachine/src/Z_Motor_Task.cpp
 *  @section sec_gripper Gripper-Motor Task
 *    This task only runs once the z-tasks has indicated that
 *    it has completed. The gripper-motors will turn on for a
 *    specified length of time to grasp an object, then wait a
 *    different specified length of time before releasing it.
 *    It's source code can be found at: 
 * 
 *    @c https://github.com/ashley1888/ME-507-Term-Project/blob/main/ME%20507%20Clawmachine/src/Gripper_Motor_Task.cpp
 *  @page page_3D 3D Printed Parts
 *  @section sec_3D 3D Printed Parts
 *    Seven 3D printed parts were originally designed and created for this project.
 *    An image of each of them can be seen below.
 *    @image html belt_clamp.png "Part 1: X-axis Belt Clamp" width=75%
 *    @image html linear_rod_support.png "Part 2: Linear Rod Support Belt Holder" width=75%
 *    @image html shaft_support_to_linear_bearing.png "Part 3: Shaft Support to Linear Bearing" width=75%
 *    @image html belt_holder.png "Part 4: Y-axis Belt Clamp" width=75%
 *    @image html x_motor_support.png "Part 5: X-motor Support" width=75%
 *    @image html z_motor_support.png "Part 6: Z-motor Support" width=75%
 *    @image html lead_screw_to_gripper.png "Part 7: Gripper-motor and Gripper Support" width=75%
 * 
 *    The gripper used for this project was not originally created, it was found 
 *    off GrabCAD, and open-source CAD library. Below is an image of the gripper.
 *    @image html gripper.png "Gripper Model" width=75%
 * 
 *    This particular gripper was designed by Avinash Bhashkar, and its source can be found at:
 *    @c https://grabcad.com/library/robotic-gripper-and-end-effector-1
 */