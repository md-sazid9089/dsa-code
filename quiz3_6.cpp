#include <bits/stdc++.h>
using namespace std;

/*
Algorithm: MinCostWalk
-----------------------------------------
1. Initialize GCD array `gcd[]` with INF (a large value).
2. Set `gcd[source] = costs[source]`.
3. Create a priority queue (min-heap) to process nodes in increasing order of GCD.
4. Push (cost[source], source) into the priority queue.
5. While the queue is not empty:
   a) Extract the node `u` with the minimum GCD from the priority queue.
   b) For each edge (u, v) in the graph:
      i. Compute the GCD of `gcd[u]` and `cost[v]`.
      ii. If `gcd[u]` combined with `cost[v]` is smaller than `gcd[v]`, update `gcd[v]`.
      iii. Push (gcd[v], v) into the priority queue.
6. Return `gcd[destination]` as the minimum cost of the walk.

-----------------------------------------
The algorithm uses a **modified Dijkstra’s algorithm**, where instead of minimizing distance, we minimize the GCD of the node costs along the path.

*/

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a);
}

int minCostWalk(int n, vector<pair<int, int>> adj[], vector<int>& costs, int source, int destination) {
    vector<int> gcdVal(n + 1, INT_MAX);  // GCD values initialized to INF
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

    // Start from the source node
    gcdVal[source] = costs[source];
    pq.push({costs[source], source});

    while (!pq.empty()) {
        int currentGCD = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we reached the destination, return the GCD value
        if (u == destination) return currentGCD;

        // Traverse neighbors of the current node
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int edgeCost = costs[v];

            // Calculate the new GCD of the path (GCD of current path and the cost of the new node)
            int newGCD = gcd(currentGCD, edgeCost);

            // If the new GCD is better, update and push to the priority queue
            if (newGCD < gcdVal[v]) {
                gcdVal[v] = newGCD;
                pq.push({newGCD, v});
            }
        }
    }

    // If there's no path to the destination, return -1
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];  // Adjacency list for the graph
    vector<int> costs(n + 1);

    // Input the costs of each node
    for (int i = 1; i <= n; i++) {
        cin >> costs[i];
    }

    // Input the edges of the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, costs[v]});
    }

    int source, destination;
    cin >> source >> destination;

    // Find the minimum cost walk
    int result = minCostWalk(n, adj, costs, source, destination);

    if (result != -1) {
        cout << "Minimum cost of the walk: " << result << endl;
    } else {
        cout << "No path exists from source to destination" << endl;
    }

    return 0;

/*
=========================== PASS SIMULATIONS ===========================
Example Input:
6 8
3 2 5 7 11 13
1 2
2 3
1 4
4 5
3 5
5 6
1 6
4 6
Source: 1
Destination: 6

Graph representation:
1 → 2 → 3 → 5 → 6
|    |    |
→ 4 → 5

Pass 1: Start from node 1 (GCD = 3)
-------------------------------------
Queue: [(3, 1)]
Explore node 1:
- GCD with 2: gcd(3, 2) = 1 → Update node 2's GCD
- GCD with 4: gcd(3, 7) = 1 → Update node 4's GCD
Push (1, 2) and (1, 4) into the queue

Pass 2: Process node 2 (GCD = 1)
-------------------------------------
Queue: [(1, 2), (1, 4)]
Explore node 2:
- GCD with 3: gcd(1, 5) = 1 → Update node 3's GCD
Push (1, 3) into the queue

Pass 3: Process node 4 (GCD = 1)
-------------------------------------
Queue: [(1, 3), (1, 4)]
Explore node 4:
- GCD with 5: gcd(1, 11) = 1 → Update node 5's GCD
Push (1, 5) into the queue

Continue similar passes until reaching node 6 with the minimum GCD = 1

Final Output:
Minimum cost of the walk: 1
=======================================================================
*/
}
