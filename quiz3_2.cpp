#include <bits/stdc++.h>
using namespace std;

void repairRoads(vector<pair<int, int>>& roads) {
    // Create a max-heap using priority queue (sorted by repair cost)
    priority_queue<pair<int, int>> pq;

    // Insert all roads into the max-heap
    for (const auto& road : roads) {
        pq.push(road);
    }

    // Now process the roads, starting with the most expensive
    int repairOrder = 1;
    while (!pq.empty()) {
        pair<int, int> road = pq.top();
        pq.pop();

        // Simulate the repair of the road
        cout << "Repair Road ID " << road.second << " with cost " << road.first
             << " (Repair Order: " << repairOrder++ << ")" << endl;
    }
}

int main() {
    // Input: number of roads
    int n;
    cin >> n;

    vector<pair<int, int>> roads;

    // Input each road's id and repair cost
    for (int i = 0; i < n; i++) {
        int id, cost;
        cin >> id >> cost;
        roads.push_back({cost, id});  // Store as (cost, id) for max-heap
    }

    // Call the repair function to simulate the repair process
    repairRoads(roads);

    return 0;
}

/*
=========================== PASS SIMULATIONS ===========================

Example Input:
5
1 100
2 300
3 50
4 200
5 150

Graph representation:
Road 1: Repair cost = 100
Road 2: Repair cost = 300
Road 3: Repair cost = 50
Road 4: Repair cost = 200
Road 5: Repair cost = 150

Pass 1: Insert all roads into the max-heap.
-------------------------------------------
Priority Queue (Max-Heap): [(300, 2), (200, 4), (100, 1), (150, 5), (50, 3)]

Pass 2: Extract the road with the highest cost (300) and repair it.
-----------------------------------------------------------
Repair Road ID 2 with cost 300 (Repair Order: 1)
Priority Queue: [(200, 4), (150, 5), (100, 1), (50, 3)]

Pass 3: Extract the road with the next highest cost (200) and repair it.
-----------------------------------------------------------
Repair Road ID 4 with cost 200 (Repair Order: 2)
Priority Queue: [(150, 5), (100, 1), (50, 3)]

Pass 4: Extract the road with the next highest cost (150) and repair it.
-----------------------------------------------------------
Repair Road ID 5 with cost 150 (Repair Order: 3)
Priority Queue: [(100, 1), (50, 3)]

Pass 5: Extract the road with the next highest cost (100) and repair it.
-----------------------------------------------------------
Repair Road ID 1 with cost 100 (Repair Order: 4)
Priority Queue: [(50, 3)]

Pass 6: Extract the road with the next highest cost (50) and repair it.
-----------------------------------------------------------
Repair Road ID 3 with cost 50 (Repair Order: 5)
Priority Queue: []

Final Output:
Repair Order: 1: Road ID 2 (Cost: 300)
Repair Order: 2: Road ID 4 (Cost: 200)
Repair Order: 3: Road ID 5 (Cost: 150)
Repair Order: 4: Road ID 1 (Cost: 100)
Repair Order: 5: Road ID 3 (Cost: 50)
=======================================================================
*/
