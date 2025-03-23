#include <bits/stdc++.h>
using namespace std;

void topologicalSort(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0);
    queue<int> q;
    vector<int> topo;

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
        topo.push_back(node);

        for (int neighbor : adj[node]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Print topological order
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int V = 6;
    vector<int> adj[V];

    // Example graph edges
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    topologicalSort(V, adj);
    return 0;
}
