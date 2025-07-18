//codigo de joao


// Robotic Arm Control Example for CoppeliaSim
// Author: Joao (original), comments and English translation by Artur
// This code demonstrates how to control a robotic arm using the CoppeliaSim remote API.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}
void Pos0(int clientID,int handler){

    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);

    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);

    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);

    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
}
void carregaVotos(int* qtdVotos, char*** votos){
    FILE* arq;
    char voto[100];
    arq = fopen("votos.txt", "r");
    arq = fopen("votes.txt", "r");
    if (arq == NULL)
    {
        printf("Nao foi possivel computar votos\n"); exit(1);
        printf("Could not load votes file\n"); exit(1);
    while (!feof(arq)){
        fscanf(arq, "%99[^\n]\n", voto);
        digitos = strlen(voto);
        (*qtdVotos)++;
        (*votos) = (char**)realloc((*votos), (*qtdVotos) * sizeof(char*));
        (*votos)[(*qtdVotos) - 1] = NULL;
        (*votos)[(*qtdVotos) - 1] = (char*) realloc((*votos)[(*qtdVotos) - 1], digitos * sizeof(char));
        strcpy((*votos)[(*qtdVotos) - 1], voto);
    }
    fclose(arq);
}

// Convert degrees to radians
float radian(float degrees) {
    float rad;
    rad = (degrees * PI) / 180;
    return rad;
}

int main(int argc, char* argv[]) {
    printf("=== Niryo One Voting System (Alternative Implementation) ===\n");
    
    char** votos = NULL;
    int qtdVotos = 0;

    carregaVotos(&qtdVotos, &votos);

    int handler = 0;

    // Connect to CoppeliaSim
    int clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);
    extApi_sleepMs(500);

    if (clientID == -1) {
        printf("ERROR: Failed to connect to CoppeliaSim!\n");
        return 0;
    } else {
        printf("SUCCESS: Connected to CoppeliaSim!\n");
    }
    
    // Process each vote sequence
    for (int i = 0; i < qtdVotos; i++) {
        int k = strlen(votos[i]);
        printf("Processing vote #%d/%d = %s\n", i + 1, qtdVotos, votos[i]);

        // Process each digit in the vote sequence
        for (int j = 0; j < k; j++) {
            if (votos[i][j] == '1') {
                simxChar handlerName1[150] = "/NiryoOne/Joint";

                    simxGetObjectHandle(clientID, handlerName1, &handler, (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)-0.20, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)-0.84, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)0.13, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(3000);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)0.1, (simxInt)simx_opmode_oneshot_wait);
            
                    strcat(handlerName1, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName1, &handler, (simxInt)simx_opmode_oneshot_wait);

                    simxChar handlerNameR1[150] = "/NiryoOne/Joint";
                    simxGetObjectHandle(clientID, handlerNameR1, &handler, (simxInt)simx_opmode_oneshot_wait);

                    Pos0(clientID,handler);
                    
                    strcat(handlerNameR1, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerNameR1, &handler, (simxInt)simx_opmode_oneshot_wait);

                    strcpy(handlerNameR1, "/NiryoOne/Joint");
                    simxGetObjectHandle(clientID, handlerNameR1, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
                }

                if (votos[i][j] == '2'){
                    simxChar handlerName2[150] = "/NiryoOne/Joint";
                    simxGetObjectHandle(clientID, handlerName2, &handler, (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-20.8418), (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-63.5543), (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(0.205), (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-23.487), (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(64.3565), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(10.2405), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);

                    strcat(handlerName2, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName2, &handler, (simxInt)simx_opmode_oneshot_wait);

                    strcpy(handlerName2, "/NiryoOne/Joint");
                    simxGetObjectHandle(clientID, handlerName2, &handler, (simxInt)simx_opmode_oneshot_wait);

                    Pos0(clientID,handler);

                    strcat(handlerName2, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName2, &handler, (simxInt)simx_opmode_oneshot_wait);

                    strcpy(handlerName2, "/NiryoOne/Joint");
                    simxGetObjectHandle(clientID, handlerName2, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
                }

                if (votos[i][j] == '3'){
                    simxChar handlerName3[150] = "/NiryoOne/Joint";
                    simxGetObjectHandle(clientID, handlerName3, &handler, (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-27.5), (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-62.6473), (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(5.06), (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-31.9732), (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(60.6), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);
    
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(16.6357), (simxInt)simx_opmode_oneshot_wait);

                    strcat(handlerName3, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName3, &handler, (simxInt)simx_opmode_oneshot_wait);

                    strcpy(handlerName3, "/NiryoOne/Joint/Link/Joint/Link/Joint/Link/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName3, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(55.6), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);

                    strcpy(handlerName3, "/NiryoOne/Joint");
                    simxGetObjectHandle(clientID, handlerName3, &handler, (simxInt)simx_opmode_oneshot_wait);

                    Pos0(clientID,handler);

                    strcat(handlerName3, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName3, &handler, (simxInt)simx_opmode_oneshot_wait);

                    strcpy(handlerName3, "/NiryoOne/Joint");
                    simxGetObjectHandle(clientID, handlerName3, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
                }
                if (votos[i][j] == '4'){
                    simxChar handlerName4[150] = "/NiryoOne/Joint";
                    simxGetObjectHandle(clientID, handlerName4, &handler, (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-18.1847), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-59.822), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-5.89), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-25.7076), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(66.7), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(10.42), (simxInt)simx_opmode_oneshot_wait);

                    strcat(handlerName4, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName4, &handler, (simxInt)simx_opmode_oneshot_wait);
                    
                    strcpy(handlerName4, "/NiryoOne/Joint/Link/Joint/Link/Joint/Link/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName4, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(60.13), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1200);

                    strcpy(handlerName4, "/NiryoOne/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName4, &handler, (simxInt)simx_opmode_oneshot_wait);

                    Pos0(clientID,handler);

                    strcat(handlerName4, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName4, &handler, (simxInt)simx_opmode_oneshot_wait);

                    strcpy(handlerName4, "/NiryoOne/Joint");
                    simxGetObjectHandle(clientID, handlerName4, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
                }
                if (votos[i][j] == '5'){
                    simxChar handlerName5[150] = "/NiryoOne/Joint";
                    simxGetObjectHandle(clientID, handlerName5, &handler, (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-23.4947), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-59.822), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-5.89), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-25.7076), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(66.7), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(10.42), (simxInt)simx_opmode_oneshot_wait);

                    strcat(handlerName5, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName5, &handler, (simxInt)simx_opmode_oneshot_wait);
                    
                    strcpy(handlerName5, "/NiryoOne/Joint/Link/Joint/Link/Joint/Link/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName5, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(58.53), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1200);

                    strcpy(handlerName5, "/NiryoOne/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName5, &handler, (simxInt)simx_opmode_oneshot_wait);

                    Pos0(clientID,handler);
                        
                    strcat(handlerName5, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName5, &handler, (simxInt)simx_opmode_oneshot_wait);

                    strcpy(handlerName5, "/NiryoOne/Joint");
                    simxGetObjectHandle(clientID, handlerName5, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
                }
                if (votos[i][j] == '6'){
                    simxChar handlerName6[150] = "/NiryoOne/Joint";
                    simxGetObjectHandle(clientID, handlerName6, &handler, (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-28.803), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-64.357), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(1.269), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-31.967), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(65.53), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(14.065), (simxInt)simx_opmode_oneshot_wait);

                    strcat(handlerName6, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName6, &handler, (simxInt)simx_opmode_oneshot_wait);
                
                    strcpy(handlerName6, "/NiryoOne/Joint/Link/Joint/Link/Joint/Link/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName6, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(61.53), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);

                    strcpy(handlerName6, "/NiryoOne/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName6, &handler, (simxInt)simx_opmode_oneshot_wait);

                    Pos0(clientID,handler);

                    strcat(handlerName6, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName6, &handler, (simxInt)simx_opmode_oneshot_wait);

                    strcpy(handlerName6, "/NiryoOne/Joint");
                    simxGetObjectHandle(clientID, handlerName6, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
                }
                if (votos[i][j] == '7'){
                    simxChar handlerName7[150] = "/NiryoOne/Joint";
                    simxGetObjectHandle(clientID, handlerName7, &handler, (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-18.634), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-61.92), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-11.475), (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-19.0962), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(71.31), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(5.0745), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(3000);
                        
                    strcat(handlerName7, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName7, &handler, (simxInt)simx_opmode_oneshot_wait);
                
                    strcpy(handlerName7, "/NiryoOne/Joint/Link/Joint/Link/Joint/Link/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName7, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(68.53), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);

                    strcpy(handlerName7, "/NiryoOne/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName7, &handler, (simxInt)simx_opmode_oneshot_wait);

                    Pos0(clientID,handler);
                    
                    strcat(handlerName7, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName7, &handler, (simxInt)simx_opmode_oneshot_wait);

                    strcpy(handlerName7, "/NiryoOne/Joint");
                    simxGetObjectHandle(clientID, handlerName7, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);

                }
                if (votos[i][j] == '8'){
                    simxChar handlerName8[150] = "/NiryoOne/Joint";
                    simxGetObjectHandle(clientID, handlerName8, &handler, (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-25.4769), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-64.028), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-7.61), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-26.8344), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(72.386), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(8.336), (simxInt)simx_opmode_oneshot_wait);

                    strcat(handlerName8, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName8, &handler, (simxInt)simx_opmode_oneshot_wait);
                    
                    strcpy(handlerName8, "/NiryoOne/Joint/Link/Joint/Link/Joint/Link/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName8, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(67.53), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);

                    strcpy(handlerName8, "/NiryoOne/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName8, &handler, (simxInt)simx_opmode_oneshot_wait);

                    Pos0(clientID,handler);

                    strcat(handlerName8, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName8, &handler, (simxInt)simx_opmode_oneshot_wait);

                    strcpy(handlerName8, "/NiryoOne/Joint");
                    simxGetObjectHandle(clientID, handlerName8, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
                }
                if (votos[i][j] == '9'){
                    simxChar handlerName9[150] = "/NiryoOne/Joint";
                    simxGetObjectHandle(clientID, handlerName9, &handler, (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-29.88), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-65.2646), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-3.72), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-31.7808), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(70.96), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(11.02), (simxInt)simx_opmode_oneshot_wait);

                    strcat(handlerName9, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName9, &handler, (simxInt)simx_opmode_oneshot_wait);
                

                    strcpy(handlerName9, "/NiryoOne/Joint/Link/Joint/Link/Joint/Link/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName9, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(65.53), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);

                    strcpy(handlerName9, "/NiryoOne/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName9, &handler, (simxInt)simx_opmode_oneshot_wait);

                    Pos0(clientID,handler);

                    strcat(handlerName9, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName9, &handler, (simxInt)simx_opmode_oneshot_wait);


                    strcpy(handlerName9, "/NiryoOne/Joint");
                    simxGetObjectHandle(clientID, handlerName9, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
                }
                if (votos[i][j] == '0'){
                    simxChar handlerName0[150] = "/NiryoOne/Joint";
                    simxGetObjectHandle(clientID, handlerName0, &handler, (simxInt)simx_opmode_oneshot_wait);

                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-26.2714), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-66.9255), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-10.075), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-26.9766), (simxInt)simx_opmode_oneshot_wait);
                    
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(79.268), (simxInt)simx_opmode_oneshot_wait);
                
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(5.994), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);

                    strcat(handlerName0, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName0, &handler, (simxInt)simx_opmode_oneshot_wait);
            
                    strcpy(handlerName0, "/NiryoOne/Joint/Link/Joint/Link/Joint/Link/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName0, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(72.268), (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);

                    strcpy(handlerName0, "/NiryoOne/Joint/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName0, &handler, (simxInt)simx_opmode_oneshot_wait);

                    Pos0(clientID,handler);
                
                    strcat(handlerName0, "/Link/Joint");
                    simxGetObjectHandle(clientID, (simxChar*)handlerName0, &handler, (simxInt)simx_opmode_oneshot_wait);

                    strcpy(handlerName0, "/NiryoOne/Joint");
                    simxGetObjectHandle(clientID, handlerName0, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                }
            }

        simxChar handlerNameConf[150] = "/NiryoOne/Joint";
        simxGetObjectHandle(clientID, handlerNameConf, &handler, (simxInt)simx_opmode_oneshot_wait);

        simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-34.5314), (simxInt)simx_opmode_oneshot_wait);
                
        simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-72.956), (simxInt)simx_opmode_oneshot_wait);
               
        simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-2.79), (simxInt)simx_opmode_oneshot_wait);
                
        simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(-35.5412), (simxInt)simx_opmode_oneshot_wait);
       
        simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(75.24), (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(2000);
          
        simxSetJointTargetPosition(clientID, handler, (simxFloat)radian(8.3587), (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(1000);
        
        strcat(handlerNameConf, "/Link/Joint");
        simxGetObjectHandle(clientID, (simxChar*)handlerNameConf, &handler, (simxInt)simx_opmode_oneshot_wait);

        strcpy(handlerNameConf, "/NiryoOne/Joint");
        simxGetObjectHandle(clientID, handlerNameConf, &handler, (simxInt)simx_opmode_oneshot_wait);

        Pos0(clientID,handler);
    
        strcat(handlerNameConf, "/Link/Joint");
        simxGetObjectHandle(clientID, (simxChar*)handlerNameConf, &handler, (simxInt)simx_opmode_oneshot_wait);

        strcpy(handlerNameConf, "/NiryoOne/Joint");
        simxGetObjectHandle(clientID, handlerNameConf, &handler, (simxInt)simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    }

    printf("fim da votacao!\n");
    simxFinish(clientID);

    return(0);
}
