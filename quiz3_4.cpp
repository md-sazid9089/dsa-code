#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];  // Adjacency list for city roads (tree)
int color[100005];        // Stores the color of each region (0 or 1)

/*
Algorithm: Minimum Cameras in Dhaka City (Tree Bipartite Approach)

Step 1: Input the number of regions (N).
Step 2: Read the N-1 roads connecting the regions and construct an adjacency list.
Step 3: Initialize all regions as uncolored (-1).
Step 4: Perform a DFS starting from node 1:
        a) Assign color 0 to the starting node.
        b) Assign alternate colors (0/1) to adjacent regions.
        c) If two adjacent nodes have the same color, return an error (not possible in a tree).
Step 5: Count the number of nodes in each color group (group0 and group1).
Step 6: The answer is the minimum of the two groups, as placing cameras in the smaller group is optimal.
Step 7: Print the minimum number of cameras needed.

*/

bool dfs(int node, int c) {
    color[node] = c;  // Assign color to the node
    for (int neighbor : adj[node]) {
        if (color[neighbor] == -1) {  // If unvisited
            // Assign alternate color and continue DFS
            if (!dfs(neighbor, 1 - c)) return false;
        } else if (color[neighbor] == color[node]) {
            // If two adjacent nodes have the same color, it's not bipartite (shouldn't happen in a tree)
            return false;
        }
    }
    return true;
}

int minCameras(int N) {
    memset(color, -1, sizeof(color));  // Step 3: Initialize all regions as uncolored (-1)

    int group0 = 0, group1 = 0;  // Step 5: Counters for two groups

    // Step 4: Start DFS from region 1
    if (!dfs(1, 0)) {
        return -1;  // If the graph is not bipartite (shouldn't happen in a tree)
    }

    // Step 5: Count nodes in each group
    for (int i = 1; i <= N; i++) {
        if (color[i] == 0) group0++;
        else group1++;
    }

    // Step 6: Return the minimum of the two groups
    return min(group0, group1);
}

int main() {
    int N;
    cin >> N;  // Number of regions

    // Step 1: Input N-1 roads and build adjacency list
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 2: Compute minimum cameras
    int result = minCameras(N);
    if (result == -1) {
        cout << "Error: Graph is not bipartite!" << endl;
    } else {
        cout << "Minimum number of cameras needed: " << result << endl;
    }

    return 0;
}

/*
=========================== PASS SIMULATIONS ===========================
Example Input:
6
1 2
1 3
2 4
2 5
3 6

Tree Structure:
    1
   / \
  2   3
 / \   \
4   5   6

Pass 1: DFS Traversal & Coloring
--------------------------------
- Start DFS from node 1 → Assign color[1] = 0
- Visit node 2 → Assign color[2] = 1
- Visit node 3 → Assign color[3] = 1
- Visit node 4 from 2 → Assign color[4] = 0
- Visit node 5 from 2 → Assign color[5] = 0
- Visit node 6 from 3 → Assign color[6] = 0

Final Coloring:
  Node 1 → Color 0
  Node 2 → Color 1
  Node 3 → Color 1
  Node 4 → Color 0
  Node 5 → Color 0
  Node 6 → Color 0

Pass 2: Counting Groups
-------------------------
- Group 0: {1, 4, 5, 6} → 4 nodes
- Group 1: {2, 3} → 2 nodes

Pass 3: Compute Minimum Cameras
-------------------------------
- Minimum cameras needed = min(4,2) = 2

Expected Output:
----------------
Minimum number of cameras needed: 2
=======================================================================
*/
