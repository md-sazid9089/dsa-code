#include <bits/stdc++.h>
using namespace std;

bool hasCycle(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0);
    queue<int> q;
    int count = 0; // Track the number of nodes processed

    // Compute in-degree of each node
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    // Push nodes with in-degree 0 into the queue
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Process nodes in BFS manner
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++; // Counting processed nodes

        for (int neighbor : adj[node]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If count != V, there is a cycle
    return (count != V);
}

int main() {
    int V = 4;
    vector<int> adj[V];

    // Example graph with a cycle: 0 -> 1 -> 2 -> 3 -> 1 (Cycle)
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // Cycle here

    if (hasCycle(V, adj)) {
        cout << "Cycle detected in the graph\n";
    } else {
        cout << "No cycle in the graph\n";
    }

    return 0;
}
