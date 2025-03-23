#include <bits/stdc++.h>
using namespace std;

void shortest_path(int v, int e) {
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }
    int s;
    cout << "Enter the starting vertex: ";
    cin >> s;
    queue<int> q;
    vector<int> distance(v, -1);
    distance[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int u : adj[curr]) {
            if (distance[u] == -1) {
                distance[u] = distance[curr] + 1;
                q.push(u);
            }
        }
    }
   cout << "Shortest distances from vertex " << s << ":\n";
    for (int i = 0; i < v; i++) {
        cout << "Vertex " << i << ": " << distance[i] << "\n";
    }
}

int main() {
    cout << "Enter number of vertices and edges: ";
    int v, e;
    cin >> v >> e;

    shortest_path(v, e);
    return 0;
}
