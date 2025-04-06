#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dirent_entry {
    char filename[11];
    int start_block, length;
    struct dirent_entry *next;
} *head = NULL, *new, *cur;

int diskSize;
int *disk;

void initializeDisk(int n) {
    diskSize = n;
    disk = (int *)calloc(diskSize, sizeof(int));
    head = NULL;
    printf("Disk initialized with %d blocks.\n", diskSize);
}

int allocateFile(char *name, int length) {
    if (length > diskSize) {
        printf("Error: Not enough disk space.\n");
        return 0;
    }
    
    for (int i = 0; i <= diskSize - length; i++) {
        int free = 1;
        for (int j = 0; j < length; j++) {
            if (disk[i + j] != 0) {
                free = 0;
                break;
            }
        }
        if (free) {
            new = (struct dirent_entry *)malloc(sizeof(struct dirent_entry));
            strcpy(new->filename, name);
            new->start_block = i;
            new->length = length;
            new->next = NULL;
            
            for (int j = 0; j < length; j++) {
                disk[i + j] = 1;
            }
            
            if (head == NULL)
                head = new;
            else {
                cur = head;
                while (cur->next != NULL)
                    cur = cur->next;
                cur->next = new;
            }
            
            printf("File %s allocated from block %d to %d.\n", name, i, i + length - 1);
            return 1;
        }
    }
    printf("Error: No contiguous space available.\n");
    return 0;
}

void displayFiles() {
    if (head == NULL) {
        printf("No files allocated.\n");
        return;
    }
    printf("\nFile Allocation Table:\n");
    printf("%-10s %-10s %-10s\n", "File", "Start", "Length");
    cur = head;
    while (cur != NULL) {
        printf("%-10s %-10d %-10d\n", cur->filename, cur->start_block, cur->length);
        cur = cur->next;
    }
}

void deleteFile(char *name) {
    struct dirent_entry *prev = NULL;
    cur = head;
    while (cur != NULL) {
        if (strcmp(cur->filename, name) == 0) {
            for (int j = 0; j < cur->length; j++) {
                disk[cur->start_block + j] = 0;
            }
            printf("File %s deleted.\n", name);
            if (prev == NULL)
                head = cur->next;
            else
                prev->next = cur->next;
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Error: File not found.\n");
}

int main() {
    int choice, n, length;
    char name[11];
    
    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);
    initializeDisk(n);
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Allocate File\n");
        printf("2. Display File Allocation Table\n");
        printf("3. Delete File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file size (in blocks): ");
                scanf("%d", &length);
                allocateFile(name, length);
                break;
            case 2:
                displayFiles();
                break;
            case 3:
                printf("Enter file name to delete: ");
                scanf("%s", name);
                deleteFile(name);
                break;
            case 4:
                printf("Exiting...\n");
                free(disk);
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
