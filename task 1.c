#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

#include "process.h"
#include "util.h"

// Assuming the Process structure is defined like this:
typedef struct {
    int pid;             // Process ID
    int priority;        // Priority of the process
    int arrival_time;    // Time when the process arrives
} Process;

// Comparator function to be used with qsort
int my_comparer(const void *this, const void *that) {
    // Cast the void pointers to Process pointers
    Process *p1 = (Process *)this;
    Process *p2 = (Process *)that;

    // Compare based on arrival_time first (ascending order)
    if (p1->arrival_time < p2->arrival_time) {
        return -1;  // p1 comes before p2
    } else if (p1->arrival_time > p2->arrival_time) {
        return 1;   // p1 comes after p2
    }

    // If arrival times are equal, compare based on priority (ascending order)
    if (p1->priority < p2->priority) {
        return -1;  // p1 has higher priority
    } else if (p1->priority > p2->priority) {
        return 1;   // p1 has lower priority
    }

    // If both arrival_time and priority are the same, compare based on pid (ascending order)
    if (p1->pid < p2->pid) {
        return -1;  // p1 has a smaller pid
    } else if (p1->pid > p2->pid) {
        return 1;   // p1 has a larger pid
    }

    // If all are equal, return 0 (they are considered equal)
    return 0;
}

int main() {
    // Sample array of processes
    Process processes[] = {
        {1, 10, 5},  // PID 1, Priority 10, Arrival Time 5
        {2, 5, 2},   // PID 2, Priority 5, Arrival Time 2
        {3, 8, 5},   // PID 3, Priority 8, Arrival Time 5
        {4, 3, 1},   // PID 4, Priority 3, Arrival Time 1
        {5, 2, 3}    // PID 5, Priority 2, Arrival Time 3
    };

    // Number of processes
    int n = sizeof(processes) / sizeof(processes[0]);

    // Sorting processes using qsort and the my_comparer function
    qsort(processes, n, sizeof(Process), my_comparer);

    // Print the sorted processes to verify the results
    printf("Sorted Processes:\n");
    for (int i = 0; i < n; i++) {
        printf("PID: %d | Priority: %d | Arrival Time: %d\n", processes[i].pid, processes[i].priority, processes[i].arrival_time);
    }

    return 0;
}
