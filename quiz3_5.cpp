#include <bits/stdc++.h>
using namespace std;
/*
Pseudocode for Topological Sorting (Kahn’s Algorithm - BFS)
------------------------------------------------------------
Algorithm TopologicalSort(N, dependencies):
    Input:
        N → Number of tasks
        dependencies → List of (u, v) pairs where task u must be done before v
    Output:
        A valid linear ordering of tasks

    Step 1: Initialize
        Create adjacency list `adj` with N empty lists
        Create array `inDegree` of size N initialized to 0
        Create queue `q`
        Create empty list `topo` for storing task order

    Step 2: Build Graph
        For each (u, v) in dependencies:
            Add v to adjacency list of u → adj[u].push_back(v)
            Increment inDegree[v] by 1

    Step 3: Find Tasks with No Dependencies
        For i = 0 to N-1:
            If inDegree[i] == 0:
                Add i to queue `q`

    Step 4: Process Tasks Using BFS
        While `q` is not empty:
            Remove task `task` from `q`
            Append `task` to `topo`

            For each neighbor `nextTask` of `task` in adj:
                Decrement inDegree[nextTask] by 1
                If inDegree[nextTask] becomes 0:
                    Add nextTask to `q`

    Step 5: Check for Cycle
        If length of `topo` == N:
            Return `topo` (valid task order)
        Else:
            Return "Error: Cycle detected, scheduling not possible"
*/

void topologicalSort(int N, vector<int> adj[]) {
    vector<int> inDegree(N, 0);
    queue<int> q;
    vector<int> topo;

    // Step 1: Compute in-degree of each node
    for (int i = 0; i < N; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    // Step 2: Push nodes with in-degree 0 into the queue
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process nodes in BFS manner
    while (!q.empty()) {
        int task = q.front();
        q.pop();
        topo.push_back(task);

        for (int neighbor : adj[task]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Step 4: Print topological order or detect cycle
    if (topo.size() == N) {
        cout << "Order of Wedding Tasks: ";
        for (int task : topo) {
            cout << task << " ";
        }
        cout << endl;
    } else {
        cout << "Error: Cycle detected, scheduling not possible" << endl;
    }
}

int main() {
    int N = 6; // Number of tasks
    vector<int> adj[N];

    // Example dependencies (task u must be done before v)
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    /*
    Step-by-step execution:
    ------------------------
    Given dependencies:
      5 → 2
      5 → 0
      4 → 0
      4 → 1
      2 → 3
      3 → 1

    Step 1: Compute In-degree
      Task:     0  1  2  3  4  5
      In-Deg:   2  2  1  1  0  0

    Step 2: Initialize Queue (tasks with inDegree = 0): [4, 5]

    Step 3: Process queue:
    Pass 1: Remove 4 → [5] → topo = [4]
            Reduce inDegree of 0, 1 → New inDegree: [1, 1, 1, 1, 0, 0]

    Pass 2: Remove 5 → [] → topo = [4, 5]
            Reduce inDegree of 2, 0 → New inDegree: [0, 1, 0, 1, 0, 0]
            Add 0, 2 to queue → [0, 2]

    Pass 3: Remove 0 → [2] → topo = [4, 5, 0]

    Pass 4: Remove 2 → [] → topo = [4, 5, 0, 2]
            Reduce inDegree of 3 → New inDegree: [0, 1, 0, 0, 0, 0]
            Add 3 to queue → [3]

    Pass 5: Remove 3 → [] → topo = [4, 5, 0, 2, 3]
            Reduce inDegree of 1 → New inDegree: [0, 0, 0, 0, 0, 0]
            Add 1 to queue → [1]

    Pass 6: Remove 1 → [] → topo = [4, 5, 0, 2, 3, 1]

    Final task order: [4, 5, 0, 2, 3, 1]
    */

    topologicalSort(N, adj);
    return 0;
}
