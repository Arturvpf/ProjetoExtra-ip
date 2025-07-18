/*
 * Niryo One Robotic Arm Controller for CoppeliaSim
 * 
 * This program controls a Niryo One robotic arm in the CoppeliaSim simulation environment
 * to simulate an electronic voting process. The arm reads digit sequences from a text file
 * and moves to "press" corresponding buttons for each digit.
 * 
 * Features:
 * - CoppeliaSim remote API integration
 * - File-based input for voting sequences
 * - Precise joint control for digit selection
 * - Automatic reset to home position
 * - Vote confirmation movements
 * 
 * Authors: [Team Member Names]
 * Course: Advanced Robotics Programming
 * Date: 2025
 */

#define PI 3.14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include CoppeliaSim remote API
extern "C" {
#include "extApi.h"
}

// Global variables for CoppeliaSim connection
int clientID;
int handler;
simxChar handlerName[150];

/**
 * Move the robotic arm to draw/select a specific digit
 * @param digit: The digit to select (0-9)
 */
void move_digit(int digit) {
    // Joint positions for each digit (0-9) - calibrated for optimal movement
    float numj3[] = {-PI / 35, PI / 45, PI / 20, PI / 20, PI / 150, PI / 45, PI / 30, -PI / 55, 0, PI / 200};
    float numj2[] = {-PI / 4, -PI / 4, -PI / 4, -PI / 4, -PI / 4.5, -PI / 4, -PI / 4, -PI / 4.5, -PI / 4, -PI / 4};
    float numj1[] = {-PI / 11, -PI / 15, -PI / 11, -PI / 10, -PI / 15, -PI / 11, -PI / 9.5, -PI / 15, -PI / 11, -PI / 9.5};
    float backj2[] = {-PI / 3.75, -PI / 3.8, -PI / 3.6, -PI / 3.55, -PI / 3.8, -PI / 3.70, -PI / 3.6, -PI / 3.9, -PI / 3.75, -PI / 3.65};

    // Time delays for each movement phase (milliseconds)
    int t1[] = {1000, 1000, 2000, 3000, 4000, 2000, 3000, 2000, 2000, 2000};
    int t2[] = {1000, 3000, 2000, 1000, 5000, 1000, 5000, 2000, 2000, 3000};
    int t3[] = {1000, 3000, 2000, 2000, 2000, 1000, 3000, 2000, 1000, 2000};
    int t4[] = {1000, 3000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000};

    printf("Moving to digit: %d\n", digit);

    // Move joint 3 to position
    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)numj3[digit], (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(t1[digit]);

    // Move joint 2 to position
    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)numj2[digit], (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(t2[digit]);

    // Move joint 1 to position
    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)numj1[digit], (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(t3[digit]);

    // Return joint 2 to intermediate position
    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)backj2[digit], (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(t4[digit]);
}

/**
 * Move the robotic arm to the initial/home position (all joints to zero)
 */
void move_to_home_position() {
    printf("Returning to home position...\n");
    
    // Reset joint 3
    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3000);

    // Reset joint 2
    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(15000);

    // Reset joint 1
    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3000);

    // Final reset of joint 2
    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
}

/**
 * Move to a defined reference point (above digit 5 position)
 */
void move_to_reference_point() {
    printf("Moving to reference point...\n");
    
    // Move joint 2 to reference position
    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 4, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(4000);

    // Move joint 1 to reference position
    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 11, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    // Move joint 3 to reference position
    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)PI / 45, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
}

/**
 * Perform vote confirmation sequence
 */
void confirm_vote() {
    printf("Confirming vote...\n");
    
    // Move to confirmation position - joint 3
    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 70, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(6000);

    // Confirmation sequence - joint 2
    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 8, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(6000);

    // Confirmation sequence - joint 1
    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 8, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(6000);

    // Final confirmation movement - joint 2
    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 3.55, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(7000);
}

/**
 * Initialize connection to CoppeliaSim
 * @return: 0 on success, -1 on failure
 */
int initialize_connection() {
    // Connect to CoppeliaSim on default port
    clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);
    extApi_sleepMs(500);

    if (clientID == -1) {
        printf("ERROR: Failed to connect to CoppeliaSim!\n");
        printf("Make sure CoppeliaSim is running and remote API is enabled.\n");
        return -1;
    } else {
        printf("SUCCESS: Connected to CoppeliaSim!\n");
        return 0;
    }
}

/**
 * Main program function
 */
int main(int argc, char* argv[]) {
    printf("=== Niryo One Robotic Arm Controller ===\n");
    printf("Starting voting simulation...\n\n");

    // Initialize connection
    if (initialize_connection() == -1) {
        return 1;
    }

    // Set initial position (above digit 5 - reference point)
    printf("Setting up initial position...\n");
    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1000);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)PI / 45, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    // Move to initial joint positions
    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 4, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(12000);

    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 11, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3000);

    // Read voting sequences from file
    int digit;
    char number[10];
    int i, len;
    FILE* file;
    
    printf("Opening voting sequences file...\n");
    file = fopen("voting_sequences.txt", "r");
    if (file == NULL) {
        printf("ERROR: Failed to open voting_sequences.txt\n");
        printf("Please ensure the file exists and contains voting sequences.\n");
        simxFinish(clientID);
        exit(1);
    } else {
        printf("SUCCESS: File opened successfully\n\n");
        
        // Process each voting sequence
        while (!feof(file)) {
            if (fscanf(file, "%s", number) == 1) {
                len = strlen(number);
                printf("Processing voting sequence: %s (length: %d)\n", number, len);
                
                // Process each digit in the sequence
                for (i = 0; i < len; i++) {
                    digit = number[i] - '0';  // Convert char to int
                    
                    if (digit >= 0 && digit <= 9) {
                        move_digit(digit);
                        move_to_reference_point();  // Return to reference point after each digit
                    } else {
                        printf("WARNING: Invalid digit '%c' encountered, skipping...\n", number[i]);
                    }
                }
                
                // Confirm vote after completing the sequence
                confirm_vote();
                move_to_reference_point();  // Return to reference point after confirmation
                
                printf("Completed voting sequence: %s\n\n", number);
            }
        }
    }
    fclose(file);

    // Return to home position at the end
    move_to_home_position();

    // Close connection
    printf("Closing connection to CoppeliaSim...\n");
    simxFinish(clientID);
    
    printf("=== Voting simulation completed successfully! ===\n");
    return 0;
}
