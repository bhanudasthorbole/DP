#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dirent_entry {
    char filename[11];
    int start_block, end_block, length;
    struct dirent_entry *next;
} *head = NULL, *cur;

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
    
    int start = -1, count = 0;
    
    for (int i = 0; i < diskSize; i++) {
        if (disk[i] == 0) {
            if (start == -1) start = i;
            count++;
            if (count == length) {
                struct dirent_entry *new_entry = (struct dirent_entry *)malloc(sizeof(struct dirent_entry));
                if (!new_entry) {
                    printf("Memory allocation failed!\n");
                    return 0;
                }
                strcpy(new_entry->filename, name);
                new_entry->start_block = start;
                new_entry->end_block = i;
                new_entry->length = length;
                new_entry->next = NULL;
                
                for (int j = start; j <= i; j++) {
                    disk[j] = 1;
                }
                
                if (head == NULL)
                    head = new_entry;
                else {
                    cur = head;
                    while (cur->next != NULL)
                        cur = cur->next;
                    cur->next = new_entry;
                }
                
                printf("File %s allocated from block %d to %d.\n", name, start, i);
                return 1;
            }
        } else {
            count = 0;
            start = -1;
        }
    }
    printf("Error: No sufficient space available.\n");
    return 0;
}

void displayFiles() {
    if (head == NULL) {
        printf("No files allocated.\n");
        return;
    }
    printf("\nFile Allocation Table:\n");
    printf("%-10s %-10s %-10s %-10s\n", "File", "Start", "End", "Length");
    cur = head;
    while (cur != NULL) {
        printf("%-10s %-10d %-10d %-10d\n", cur->filename, cur->start_block, cur->end_block, cur->length);
        cur = cur->next;
    }
}

void deleteFile(char *name) {
    struct dirent_entry *prev = NULL;
    cur = head;
    while (cur != NULL) {
        if (strcmp(cur->filename, name) == 0) {
            for (int j = cur->start_block; j <= cur->end_block; j++) {
                disk[j] = 0;
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
