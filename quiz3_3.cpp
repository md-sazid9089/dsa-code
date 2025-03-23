#include <bits/stdc++.h>
using namespace std;

// Graph Representation
vector<pair<int, int>> adj[100005];  // Adjacency list (node, weight)
const int INF = 1e9;  // Infinity value for initialization

/*
Algorithm: Dijkstra’s Shortest Path (Without Recursion)
Step 1: Initialize the `dist[]` array with INF, except `dist[Motijeel] = 0`
Step 2: Use a priority queue (min-heap) to pick the node with the smallest travel time
Step 3: Process all neighbors and update distances
Step 4: If Uttara is reached, return the travel time
Step 5: If no path exists, return "No Route Available"
*/

int dijkstra(int source, int destination, int N) {
    vector<int> dist(N + 1, INF);  // Step 1: Distance array initialized to INF
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Step 2: Start from source (Motijeel)
    dist[source] = 0;
    pq.push({0, source});  // (time, node)

    while (!pq.empty()) {
        int time = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Step 4: If destination reached, return time
        if (u == destination) return time;

        // Step 3: Process neighbors
        for (auto [v, weight] : adj[u]) {
            int newTime = time + weight;
            if (newTime < dist[v]) {  // If found a shorter path
                dist[v] = newTime;
                pq.push({newTime, v});
            }
        }
    }

    return -1;  // Step 5: If Uttara is unreachable, return -1
}

int main() {
    int N, M, U, E;
    cin >> N >> M >> U >> E;  // N = Nodes, M = Motijeel, U = Uttara, E = Edges

    // Step 1: Input Graph (One-Way & Bidirectional Roads)
    for (int i = 0; i < E; i++) {
        int u, v, w, d;
        cin >> u >> v >> w >> d;  // u -> v with weight w, d = 1 for one-way, d = 2 for bidirectional
        adj[u].push_back({v, w});
        if (d == 2) adj[v].push_back({u, w});  // Bidirectional
    }

    // Step 2: Compute shortest path
    int result = dijkstra(M, U, N);
    if (result == -1)
        cout << "No Route Available" << endl;
    else
        cout << "Fastest time from Motijeel to Uttara: " << result << " minutes" << endl;

    return 0;
}

/*
=========================== PASS SIMULATIONS ===========================
Example Input:
6 1 6 7
1 2 10 2
1 3 15 1
2 4 12 1
3 5 10 2
4 6 10 1
5 6 5 2
2 5 2 1

Graph Representation:
Motijeel (1) → Uttara (6)
    1 --(10)--> 2 --(12)--> 4 --(10)--> 6
    1 --(15)--> 3 --(10)--> 5 --(5)--> 6
    2 --(2)--> 5 (Direct one-way)

Pass 1: Initialize Distance Array
---------------------------------
Node  Distance
1     0
2     INF
3     INF
4     INF
5     INF
6     INF

Pass 2: Process Nodes Using Priority Queue
------------------------------------------
- Extract 1 (Min Time: 0), Relax Edges:
  - 1 → 2 (Time 10), 1 → 3 (Time 15)

- Extract 2 (Min Time: 10), Relax Edges:
  - 2 → 4 (Time 22), 2 → 5 (Time 12)

- Extract 5 (Min Time: 12), Relax Edges:
  - 5 → 6 (Time 17) (Shortest Path Found!)

- Extract 3 (Time 15), Relax Edges:
  - 3 → 5 (Time 25) (Ignored, since 12 is better)

- Extract 4 (Time 22), Relax Edges:
  - 4 → 6 (Time 32) (Ignored, since 17 is better)

Pass 3: Compute Minimum Time
----------------------------
- Fastest time from Motijeel (1) to Uttara (6) = 17 minutes

Expected Output:
----------------
Fastest time from Motijeel to Uttara: 17 minutes
=======================================================================
*/
