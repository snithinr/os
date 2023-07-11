#include <stdio.h>

#define MAX_PARTITIONS 5

struct Partition {
    int id;
    int size;
    int occupied;
    int occupiedSize;
    int processId;
};

struct Partition partitions[MAX_PARTITIONS];

void initializePartitions() {
    int i;
    for (i = 0; i < MAX_PARTITIONS; i++) {
        partitions[i].id = i;
        partitions[i].size = 50;
        partitions[i].occupied = 0;
        partitions[i].processId = -2;
        partitions[i].occupiedSize = 0;
    }
}

int allocateMemory(int processId, int size) {
    int i;
    for (i = 0; i < MAX_PARTITIONS; i++) {
        if (partitions[i].occupied == 0 && partitions[i].size >= size) {
            partitions[i].occupied = 1;
            partitions[i].occupiedSize = size;
            partitions[i].processId = processId;
            printf("Process %d allocated %d units of memory in Partition %d\n", processId, size, partitions[i].id);
            return 1;
        }
    }
    printf("Process %d cannot be allocated memory.\n", processId);
    return 0;
}

void deallocateMemory(int processId) {
    int i;
    for (i = 0; i < MAX_PARTITIONS; i++) {
        if (partitions[i].occupied == 1 && partitions[i].processId == processId) {
            partitions[i].occupied = 0;
            partitions[i].occupiedSize = 0;
            partitions[i].processId = -1;
            printf("Process %d deallocated its memory from Partition %d\n", processId, partitions[i].id);
            return;
        }
    }
    printf("Process %d does not have any allocated memory.\n", processId);
}

void displayMemoryStatus() {
    int i;
    printf("Partition\tSize\tOccupiedSize\tOccupied\tProcess\n");
    for (i = 0; i < MAX_PARTITIONS; i++) {
        printf("%d\t\t%d\t%d\t\t%d\t\t", partitions[i].id, partitions[i].size, partitions[i].occupiedSize,partitions[i].occupied);
        if (partitions[i].occupied == 1) {
            printf("%d", partitions[i].processId);
        }
        printf("\n");
    }
}

int main() {
    initializePartitions();

    allocateMemory(1, 30);
    allocateMemory(2, 50);
    allocateMemory(3, 20);
    displayMemoryStatus();

    deallocateMemory(2);
    displayMemoryStatus();

    allocateMemory(4, 60);
    displayMemoryStatus();

    return 0;
}
