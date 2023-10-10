#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
} Process;

void generate_random_processes(Process processes[], int num_processes) {
    srand(time(NULL));
    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i + 1;
        processes[i].arrival_time = rand() % 10; // Random arrival time (0-9)
        processes[i].burst_time = rand() % 20 + 1; // Random burst time (1-20)
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
}

void sjrf(Process processes[], int num_processes, int max_time_units) {
    int current_time = 0;
    int completed_processes = 0;

    while (current_time < max_time_units) {
        int shortest_job = -1;
        int shortest_time = INT_MAX;

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_time && processes[i].remaining_time > 0) {
                shortest_job = i;
                shortest_time = processes[i].remaining_time;
            }
        }

        if (shortest_job == -1) {
            current_time++;
        } else {
            processes[shortest_job].remaining_time--;
            if (processes[shortest_job].remaining_time == 0) {
                completed_processes++;
                processes[shortest_job].turnaround_time = current_time - processes[shortest_job].arrival_time;
                processes[shortest_job].waiting_time = processes[shortest_job].turnaround_time - processes[shortest_job].burst_time;
            }
            current_time++;
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 5; // Change this according to your requirements
    int max_time_units = 100; // Set the maximum simulation time

    generate_random_processes(processes, num_processes);

    sjrf(processes, num_processes, max_time_units);

    // Calculate and print average waiting time and turnaround time
    float avg_waiting_time = 0.0;
    float avg_turnaround_time = 0.0;

    for (int i = 0; i < num_processes; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }

    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
