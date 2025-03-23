#include <bits/stdc++.h>
using namespace std;
bool isBipartite(vector<vector<int>>& adj, int v) {
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
                        return false;                     }
                }
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int scenario = 1; scenario <= t; scenario++) {
        int bugs, interactions;
        cin >> bugs >> interactions;

        vector<vector<int>> adj(bugs);

        for (int i = 0; i < interactions; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << "Scenario #" << scenario << ":\n";
        if (isBipartite(adj, bugs)) {
            cout << "No suspicious bugs found!\n";
        } else {
            cout << "Suspicious bugs found!\n";
        }
    }
    return 0;
}

