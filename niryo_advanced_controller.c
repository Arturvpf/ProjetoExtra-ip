/*
 * Alternative Niryo One Controller Implementation
 * 
 * This file contains an alternative implementation of the robotic arm controller
 * using a modular approach with separate functions for different operations.
 * 
 * Authors: [Team Member Names]
 */

#define PI 3.14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include CoppeliaSim remote API
extern "C" {
#include "extApi.h"
}

// Global variables
int clientID;
int handler;
simxChar handlerName[150];


// Move the robotic arm to the initial position (all joints to zero)
void InitialPosition() {
    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3000);

    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(15000);

    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3000);

    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
}


// Move the robotic arm to a defined point (example: above number 5)
void DefinedPoint() {
    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 4, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(4000);


    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 11, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);


    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)PI / 45, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
}

// Confirm vote sequence
void ConfirmVote() {
    printf("Confirming vote...\n");
    
    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 70, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(6000);

    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 8, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(6000);

    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 8, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(6000);

    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 3.55, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(7000);
}

// Execute voting movement for a specific digit
void Vote(float numj3, float numj2, float numj1, float backj2, int tempo1, int tempo2, int tempo3, int tempo4) {
    printf("Executing vote movement...\n");
    
    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)numj3, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(tempo1);

    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)numj2, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(tempo2);

    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)numj1, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(tempo3);

    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)backj2, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(tempo4);
}

int main(int argc, char* argv[]) {
    printf("=== Alternative Niryo One Controller ===\n");
    
    handler = 0;

    // Connect to CoppeliaSim
    clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);
    extApi_sleepMs(500);

    if (clientID == -1) {
        printf("ERROR: Failed to connect to CoppeliaSim!\n");
        return 0;
    } else {
        printf("SUCCESS: Connected to CoppeliaSim!\n");
    }

    // Set central point for robot movement (above number 5)
    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1000);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)PI / 45, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 4, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(12000);

    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 11, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3000);

    // Joint position arrays for digits 0-9
    float numj3[] = {-PI / 35, PI / 45, PI / 20, PI / 20, PI / 150, PI / 45, PI / 30, -PI / 55, 0, PI / 200};
    float numj2[] = {-PI / 4, -PI / 4, -PI / 4, -PI / 4, -PI / 4.5, -PI / 4, -PI / 4, -PI / 4.5, -PI / 4, -PI / 4};
    float numj1[] = {-PI / 11, -PI / 15, -PI / 11, -PI / 10, -PI / 15, -PI / 11, -PI / 9.5, -PI / 15, -PI / 11, -PI / 9.5};
    float backj2[] = {-PI / 3.75, -PI / 3.8, -PI / 3.6, -PI / 3.55, -PI / 3.8, -PI / 3.70, -PI / 3.6, -PI / 3.9, -PI / 3.75, -PI / 3.65};

    // Timing arrays for movements (milliseconds)
    float t1[] = {1000, 1000, 2000, 3000, 4000, 2000, 3000, 2000, 2000, 2000};
    float t2[] = {1000, 3000, 2000, 1000, 5000, 1000, 5000, 2000, 2000, 3000};
    float t3[] = {1000, 3000, 2000, 2000, 2000, 1000, 3000, 2000, 1000, 2000};
    float t4[] = {1000, 3000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000};
    
    char number[10];
    int cont = 0, len, digit;

    FILE* file;
    file = fopen("voting_sequences.txt", "r");
    if (file == NULL) {
        printf("ERROR: Failed to open file\n");
        exit(1);
    } else {
        printf("SUCCESS: File opened successfully\n");
        while (!feof(file)) {
            if (fscanf(file, "%s", number) == 1) {
                len = strlen(number);
                printf("Processing sequence: %s\n", number);
                
                for (cont = 0; cont < len; cont++) {
                    digit = number[cont] - '0';  // Convert char to int
                    
                    if (digit >= 0 && digit <= 9) {
                        Vote(numj3[digit], numj2[digit], numj1[digit], backj2[digit], 
                             (int)t1[digit], (int)t2[digit], (int)t3[digit], (int)t4[digit]);
                        
                        // Return to defined point
                        DefinedPoint();
                    }
                }
                
                // Confirm vote if sequence is complete
                if (cont == len) {
                    ConfirmVote();
                    DefinedPoint();  // Return to defined point
                }
            }
        }
        fclose(file);
        
        // Return to initial position
        InitialPosition();
    }

    simxFinish(clientID);
    printf("=== Program completed successfully! ===\n");
    return 0;
}
