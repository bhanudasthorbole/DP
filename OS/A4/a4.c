#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int processes, resources;
int Allocation[MAX_PROCESSES][MAX_RESOURCES];
int Max[MAX_PROCESSES][MAX_RESOURCES];
int Need[MAX_PROCESSES][MAX_RESOURCES];
int Available[MAX_RESOURCES];
int TotalResources[MAX_RESOURCES]; // Added array for total instances

// Function to calculate Need matrix
void calculateNeed() {
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
}

// Function to compute total instances of each resource
void calculateTotalResources() {
    for (int j = 0; j < resources; j++) {
        TotalResources[j] = Available[j]; // Start with available resources
        for (int i = 0; i < processes; i++) {
            TotalResources[j] += Allocation[i][j]; // Add allocated resources
        }
    }
}

// Function to check if the system is in a safe state
int isSafe() {
    int work[MAX_RESOURCES], finish[MAX_PROCESSES] = {0};
    for (int i = 0; i < resources; i++) {
        work[i] = Available[i];
    }

    int safeSeq[MAX_PROCESSES];
    int count = 0;

    while (count < processes) {
        int found = 0;
        for (int i = 0; i < processes; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < resources; j++) {
                    if (Need[i][j] > work[j])
                        break;
                }
                if (j == resources) {
                    for (int k = 0; k < resources; k++) {
                        work[k] += Allocation[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state!\n");
            return 0;
        }
    }

    printf("System is in a safe state. Safe sequence is: ");
    for (int i = 0; i < processes; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");
    return 1;
}

// Function to display matrices
void displayMatrices() {
    printf("\nProcess\t Allocation\t Max\t\t Need\n");
    for (int i = 0; i < processes; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < resources; j++) {
            printf("%d ", Allocation[i][j]);
        }
        printf("\t\t");
        for (int j = 0; j < resources; j++) {
            printf("%d ", Max[i][j]);
        }
        printf("\t\t");
        for (int j = 0; j < resources; j++) {
            printf("%d ", Need[i][j]);
        }
        printf("\n");
    }
}

// Function to display total instances of each resource
void displayTotalResources() {
    printf("\nTotal Instances of Resources: ");
    for (int i = 0; i < resources; i++) {
        printf("%d ", TotalResources[i]);
    }
    printf("\n");
}

// Main function
int main() {
    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter number of resources: ");
    scanf("%d", &resources);

    printf("Enter Allocation matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("Enter Max matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &Max[i][j]);
        }
    }

    printf("Enter Available resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &Available[i]);
    }

    // Calculate Need and Total Resources
    calculateNeed();
    calculateTotalResources();
    
    // Display matrices
    displayMatrices();
    
    // Display total instances of each resource
    displayTotalResources();
    
    // Check if the system is in a safe state
    isSafe();

    return 0;
}
