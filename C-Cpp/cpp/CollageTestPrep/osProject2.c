#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct Process {
    int id;
    int at;
    int bt;
    int wt;
    int tat;
    int rt;
} Process;

void randomProcess(Process p[], int no_processes) {
    srand(time(NULL));
    for (int i = 0; i < no_processes; i++) {
        p[i].id = i + 1;
        p[i].at = rand() % 10;
        p[i].bt = rand() % 100 + 1;
        p[i].rt = p[i].bt;
        p[i].wt = 0;
        p[i].tat = 0;
    }
}

void sjrf(Process p[], int no_processes, int max_time) {
    int ct = 0;
    int cp = 0;

    while (ct < max_time) {
        int sj = -1;
        int st = INT_MAX;

        for (int i = 0; i < no_processes; i++) {
            if (p[i].at <= ct && p[i].rt < st && p[i].rt > 0) {
                sj = i;
                st = p[i].rt;
            }
        }

        if (sj == -1) {
            ct++;
        } else {
            p[sj].rt--;
            if (p[sj].rt == 0) {
                cp++;
                p[sj].tat = ct - p[sj].at;
                p[sj].wt = p[sj].tat - p[sj].bt;
            }
            ct++;
        }
    }
}

int main() {
    Process p[10];
    int no_processes = 10;
    int max_time = 100;

    randomProcess(p, no_processes);

    sjrf(p, no_processes, max_time);

    // Calculate and print average waiting time and turnaround time
    float avg_wt = 0.0;
    float avg_tat = 0.0;

    for (int i = 0; i < no_processes; i++) {
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    avg_wt /= no_processes;
    avg_tat /= no_processes;

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}