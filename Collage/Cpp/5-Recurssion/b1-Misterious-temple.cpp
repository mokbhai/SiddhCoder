// problem statement
// the misterious temple and 
// Deep inside the ancient temple of recurssia, there is a stair case leading to treasure room.
// the stair case has n steps, each step has a magical number written on it.
// A traveller can only move forword by jumping over exactly the number written on the current step.
// the traveller starts from the first step index and wants to reach the last step index = n - 1. howeaver not all paths are possible, some paths may lead to dead ends.
// your task is to determine if the traveller can reach the last step index or not. return true if it's possible, otherwise false.
// Test cases:

// Input:
// n = 5
// steps[] = {2, 3, 1, 1, 1}
// Output: true

#include <iostream>
using namespace std;

bool canReachLastStep(int steps[], int n, int i) {
    if (n-1 == i) return true;
    else if (i >= n || steps[i] == 0) return false;

    return canReachLastStep(steps, n, i+steps[i]);
}

int main() {
    int n; cin >> n;
    int steps[n]; for(int i=0;i<n;i++) cin >> steps[i];

    bool ans = canReachLastStep(steps, n, 0);
    cout << (ans ? "true" : "false");
}