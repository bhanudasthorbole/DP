#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int allocation[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES], need[MAX_PROCESSES][MAX_RESOURCES];
int n, m; // n: number of processes, m: number of resources

void calculateNeed() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

void displayData() {
    printf("\nProcess\t Allocation\t Max\t\t Need\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < m; j++)
	{
            printf("%d ", allocation[i][j]);
	}
        printf(" \t\t");

        for (int j = 0; j < m; j++)
	{
            printf("%d ", max[i][j]);
	}
        printf(" \t\t");

        for (int j = 0; j < m; j++)
	{
            printf("%d ", need[i][j]);
	}
        printf("\n");
    }

    printf("\nAvailable Resources: ");
    for (int i = 0; i < m; i++)
        printf("%d ", available[i]);
    printf("\n");
}

int isSafe() {
    int work[MAX_RESOURCES], finish[MAX_PROCESSES] = {0};
    for (int i = 0; i < m; i++)
        work[i] = available[i];

    int safeSeq[MAX_PROCESSES], count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        break;
                if (j == m) {
                    for (int k = 0; k < m; k++)
                        work[k] += allocation[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("\nSystem is NOT in a Safe State..!\n");
            return 0;
        }
    }
    printf("\nSystem is in a Safe State.\nSafe Sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
    return 1;
}

void requestResources(int process, int request[]) {
    printf("\nProcess P%d is requesting resources: ", process);
    for (int i = 0; i < m; i++)
        printf("%d ", request[i]);
    printf("\n");

    for (int i = 0; i < m; i++)
        if (request[i] > need[process][i] || request[i] > available[i]) {
            printf("Request Cannot Be Granted....\n");
            return;
        }

    for (int i = 0; i < m; i++) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }

    if (isSafe()) {
        printf("Request Granted.....\n");
    } else {
        for (int i = 0; i < m; i++) {
            available[i] += request[i];
            allocation[process][i] -= request[i];
            need[process][i] += request[i];
        }
        printf("Request denied to keep the system safe.\n");
    }

    displayData();
}

void getInput() {
//    printf("Enter number of processes and resources: ");
//    scanf("%d %d", &n, &m);

	
	printf("\n Enter Number of Processes : ");
        scanf("%d", &n);
	printf("\n Enter Number of Resources : ");
        scanf("%d", &m);
    
    
    
    
    
    printf("\n Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    }

    printf("\n Enter Max Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    printf("\n Enter Available Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &available[i]);

    calculateNeed();
}

int main() {
    getInput();
    displayData();

    if (!isSafe()) return 0;

    int process, request[MAX_RESOURCES];
    printf("\nEnter Process Number Making Request (0 to %d): P", n - 1);
    scanf("%d", &process);
    printf("Enter Requested Resources: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &request[i]);

    requestResources(process, request);
    return 0;
}
