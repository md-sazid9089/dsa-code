#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& adj, int v, int src) {
    vector<int> dist(v, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : adj[curr]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }
    return dist;
}

int main() {
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> adj(v);
    cout << "Enter " << e << " edges (0-based index):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> distances = shortestPath(adj, v, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < v; i++) {
        cout << "To " << i << ": " << distances[i] << "\n";
    }

    return 0;
}
