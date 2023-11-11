
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
        processes[i].arrival_time = rand() % 100; // random arrival time (00-99)
        processes[i].burst_time = rand() % 20 + 1; // Random burst time (1-20)
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
}

void sortOnBrustTime(Process processes[], int num_processes)
{
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                // Swap processes[j] and processes[j + 1]
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void sjrf(Process processes[], int num_processes, int max_time_units) {
    int current_time = 0;
    int completed_processes = 0;

    printf("\nProcesses completed in order :- \n");

    while (completed_processes < num_processes) {
        int shortest_job = -1;
        int shortest_time = INT_MAX;

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (processes[i].remaining_time < shortest_time) {
                    shortest_job = i;
                    shortest_time = processes[i].remaining_time;
                }
            }
        }

        if (shortest_job == -1) {
            current_time++;
        } else {
            processes[shortest_job].remaining_time--;
            if (processes[shortest_job].remaining_time == 0) {
                completed_processes++;
                processes[shortest_job].turnaround_time = current_time - processes[shortest_job].arrival_time + 1;
                processes[shortest_job].waiting_time = processes[shortest_job].turnaround_time - processes[shortest_job].burst_time;
                printf("%d -> ",processes[shortest_job].id);
            }
            current_time++;
        }
    }
    printf("All Done\n\n");
}

void printResults(Process processes[], int num_processes) {
    printf("Process  Arrival Time  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%7d %13d %11d %13d %15d\n", processes[i].id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 10; // Change this according to your requirements
    int max_time_units = 100; // Set the maximum simulation time

    generate_random_processes(processes, num_processes);

    sjrf(processes, num_processes, max_time_units);

    printResults(processes, num_processes);

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

//// Report :-

/// Base Case :- 
// Process  Arrival Time  Burst Time
//       1            40           7
//       2            56           7
//       3            88           2
//       4            49          13
//       5            34          18
//       6            24          14
//       7            88           2
//       8            92           3
//       9            75          15
//      10            51          13

/// SJRF (Shortest Job Remaining First) Scheduling Algorithm :- 
// Process  Arrival Time  Burst Time  Waiting Time  Turnaround Time
//       1            40           7             0               7
//       2            56           7             6              13
//       3            88           2             0               2
//       4            49          13             0              13
//       5            34          18            51              69
//       6            24          14             0              14
//       7            88           2             2               4
//       8            92           3             0               3
//       9            75          15            28              43
//      10            51          13            18              31

// SJRF Execution Order
// 3 -> 7 -> 8 -> 6 -> 1 -> 2 -> 10 -> 9 -> 4 -> 5

// Average Waiting Time for sjrf: 10.50
// Average Turnaround Time for sjrf: 19.90

/// Round Robin Scheduling Algorithm :-
// Assuming a time quantum of 4 units for Round Robin:

// Process	Arrival Time	Burst Time	Waiting Time	Turnaround Time
// 1        40              7	        25	            32
// 2        56          	7	        51	            58
// 3        88          	2	        57	            59
// 4        49          	13      	59          	72
// 5        34          	18      	74          	92
// 6        24          	14      	92          	106
// 7        88          	2	        64	            66
// 8        92          	3	        83	            86
// 9        75          	15      	77          	92
// 10       51          	13      	98          	111
// Average Waiting Time for RR = 70.0
// Average Turnaround Time for RR = 79.4

/// FCFS (First Come First Serve) Scheduling Algorithm :-
// Process	Arrival Time	Burst Time	Waiting Time	Turnaround Time
// 1        40          	7	        0	            7
// 2        56          	7	        7	            14
// 3        88          	2	        14	            16
// 4        49          	13      	16	            29
// 5        34          	18      	29	            47
// 6        24          	14      	47	            61
// 7        88          	2	        61	            63
// 8        92          	3	        63	            66
// 9        75          	15      	66	            81
// 10       51          	13      	81	            94
// Average Waiting Time for FCFS = 40.4
// Average Turnaround Time for FCFS = 52.8

//// Conclusion :- 
// Round Robin (RR) has the highest average waiting time and turnaround time among the three scheduling algorithms.
// First Come First Serve (FCFS) has intermediate average waiting and turnaround times.
// Shortest Job First (SJF) has the lowest average waiting time and turnaround time, indicating it is the most efficient scheduling algorithm for this set of processes.
// SJF minimizes waiting and turnaround times by selecting the shortest job to execute next, leading to better overall performance.
