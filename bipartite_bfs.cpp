#include <bits/stdc++.h>
using namespace std;
bool isBipartite(vector<vector<int>> &adj, int v) {
    vector<int> color(v, -1);
    for (int i = 0; i < v; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int neighbor : adj[curr]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[curr];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[curr]) {
                        return false;                    }
                }
            }
        }
    }
    return true;
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

    if (isBipartite(adj, v)) {
        cout << "The graph is Bipartite.\n";
    } else {
        cout << "The graph is NOT Bipartite.\n";
    }

    return 0;
}
