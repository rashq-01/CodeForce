#include<bits/stdc++.h>

#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

int find(int i,vector<int>& parent){
    if(i==parent[i])return i;

    return parent[i] = find(parent[i],parent);
}

// void Union(int x, int y,vector<int>& parent){
//     int parent_x = find(x,parent);
//     int parent_y = find(y,parent);


//     if(parent_x != parent_y){
//         parent[parent_x] = parent_y;
//     }

// }

void Union(int x, int y, vector<int>& parent, vector<int>& rank,int& M){
    int parent_x = find(x,parent);
    int parent_y = find(y,parent);

    if(parent_x == parent_y)return;

    M--;
    if(rank[parent_x] > rank[parent_y]){
        parent[parent_y] = parent_x;
    }
    else if(rank[parent_y] > rank[parent_x]){
        parent[parent_x] = parent_y;
    }
    else{
        parent[parent_x] = parent_y;
        rank[parent_y]++;
    }
}



int earliestFullConnection(int n,vector<vector<int>>& events){
    sort(events.begin(),events.end());

    int N = n ;

    vector<int> parent(n);
    vector<int> rank(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i] = 0;
    }

    for(auto& ev : events){
        int timeStamp = ev[0];
        int u = ev[1];
        int v = ev[2];
        Union(u,v,parent,rank,N);
        if(N==1)return timeStamp;

    }

    return -1;
}

// ==========================================
// TEST FRAMEWORK
// ==========================================
struct TestCase {
    string name;
    int n;
    vector<vector<int>> events;
    int expected;
};

void runTest(int testNum, const TestCase& tc) {
    cout << "Test " << testNum << " [" << tc.name << "]... ";
    
    vector<vector<int>> evts = tc.events;
    
    auto start = high_resolution_clock::now();
    int result = earliestFullConnection(tc.n, evts);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(stop - start);
    
    if (result == tc.expected) {
        cout << "\033[1;32mPASSED\033[0m (" << duration.count() << " ms)\n";
    } else {
        cout << "\033[1;31mFAILED\033[0m\n";
        cout << "  Expected: " << tc.expected << " | Output: " << result << "\n";
    }
}

int main() {
    cout << "=================================================\n";
    cout << "  BRUTAL TEST SUITE - EARLIEST FULL CONNECTION   \n";
    cout << "=================================================\n\n";

    vector<TestCase> tests;

    // ---------------------------------------------------------
    // 1. SAMPLE CASE 1 (From Problem Description)
    // ---------------------------------------------------------
    {
        int n = 6;
        vector<vector<int>> events = {
            {20190101,0,1}, {20190104,3,4}, {20190107,2,3}, 
            {20190211,1,5}, {20190224,2,4}, {20190301,0,3}, 
            {20190312,1,2}, {20190322,4,5}
        };
        tests.push_back({"Sample Case 1 (Merge Components)", n, events, 20190301});
    }

    // ---------------------------------------------------------
    // 2. SAMPLE CASE 2 (Progressive Connection)
    // ---------------------------------------------------------
    {
        int n = 4;
        vector<vector<int>> events = {{0,2,0}, {1,0,1}, {3,0,3}, {4,1,2}, {7,3,1}};
        tests.push_back({"Sample Case 2 (Progressive Chain)", n, events, 3});
    }

    // ---------------------------------------------------------
    // 3. SAMPLE CASE 3 (Never Connected)
    // ---------------------------------------------------------
    {
        int n = 3;
        vector<vector<int>> events = {{2,0,1}, {2,1,0}};
        tests.push_back({"Sample Case 3 (Disconnected Graph Trap)", n, events, -1});
    }

    // ---------------------------------------------------------
    // 4. UNSORTED TIME TRAP
    // ---------------------------------------------------------
    {
        int n = 4;
        vector<vector<int>> events = {{10, 0, 1}, {1, 1, 2}, {5, 2, 3}};
        tests.push_back({"Unsorted Events Trap (Must Sort)", n, events, 10});
    }

    // ---------------------------------------------------------
    // 5. REDUNDANT EDGE TRAP 
    // ---------------------------------------------------------
    {
        int n = 3;
        vector<vector<int>> events = {
            {1, 0, 1}, {2, 0, 1}, {3, 1, 0}, {4, 1, 2}, {5, 2, 1}
        };
        tests.push_back({"Redundant Cyclic Edges Trap", n, events, 4});
    }

    // ---------------------------------------------------------
    // 6. SIMULTANEOUS EVENTS TRAP
    // ---------------------------------------------------------
    {
        int n = 5;
        vector<vector<int>> events = {
            {100, 0, 1}, {100, 1, 2}, {100, 2, 3}, {100, 3, 4}
        };
        tests.push_back({"Simultaneous Events Timestamp Trap", n, events, 100});
    }

    // ---------------------------------------------------------
    // 7. MAXIMUM CONSTRAINTS - STRESS TEST (N=10000)
    // Connecting nodes sequentially, expected time is exactly N-1 (9999).
    // Shuffled to force candidate to sort efficiently.
    // ---------------------------------------------------------
    {
        int n = 10000;
        vector<vector<int>> events;
        for (int i = 0; i < n - 1; i++) {
            events.push_back({i + 1, i, i + 1});
        }
        mt19937 rng(42); 
        shuffle(events.begin(), events.end(), rng);
        
        tests.push_back({"Max Constraint Stress Test (N=10,000)", n, events, 9999});
    }

    // ---------------------------------------------------------
    // 8. MAX CONSTRAINTS DISCONNECTED (N=10000)
    // Missing the final edge to connect node 9999. Must return -1.
    // ---------------------------------------------------------
    {
        int n = 10000;
        vector<vector<int>> events;
        for (int i = 0; i < n - 2; i++) {
            events.push_back({i + 1, i, i + 1});
        }
        tests.push_back({"Max Disconnected Constraint (N=10,000)", n, events, -1});
    }

    // ---------------------------------------------------------
    // 9. EXTREME TIMESTAMPS (T = 10^9)
    // Array allocation using timestamps will segfault here.
    // ---------------------------------------------------------
    {
        int n = 2;
        vector<vector<int>> events = {{1000000000, 0, 1}};
        tests.push_back({"Max Timestamp Overflow Trap (T=10^9)", n, events, 1000000000});
    }

    // ---------------------------------------------------------
    // 10. STAR GRAPH WITH DELAYED CENTER
    // Central node 0 connects to everything. Max time is (N-1)*10.
    // ---------------------------------------------------------
    {
        int n = 1000;
        vector<vector<int>> events;
        for(int i = 1; i < n; i++) {
            events.push_back({i * 10, 0, i});
        }
        mt19937 rng(1337); 
        shuffle(events.begin(), events.end(), rng);
        tests.push_back({"Star Graph Configuration (N=1000)", n, events, 9990});
    }

    // ---------------------------------------------------------
    // 11. MASSIVE SIMULTANEOUS BURST
    // 10,000 nodes all connected at the exact same millisecond.
    // Fails algorithms that overwrite the 'earliest' tracker incorrectly on ties.
    // ---------------------------------------------------------
    {
        int n = 10000;
        vector<vector<int>> events;
        for (int i = 0; i < n - 1; i++) {
            events.push_back({55555, i, i + 1});
        }
        tests.push_back({"Simultaneous Massive Burst (Same T)", n, events, 55555});
    }

    // ---------------------------------------------------------
    // 12. TWO DENSE ISLANDS (THE DUMBBELL GRAPH)
    // Two giant clusters that connect early, but the single bridge 
    // connecting them happens at the very end of time.
    // ---------------------------------------------------------
    {
        int n = 10000;
        vector<vector<int>> events;
        for (int i = 0; i < 4999; i++) events.push_back({10, i, i + 1});
        for (int i = 5000; i < 9999; i++) events.push_back({10, i, i + 1});
        events.push_back({1000000000, 4999, 5000}); // The bridge
        mt19937 rng(777); 
        shuffle(events.begin(), events.end(), rng);
        tests.push_back({"Dumbbell Graph with Delayed Bridge", n, events, 1000000000});
    }

    // ---------------------------------------------------------
    // 13. EARLY CONNECTION + 10k LATE NOISY EVENTS
    // Graph connects at T=4. Then 9,996 redundant edges drop.
    // Fails algorithms that don't break early and overwrite the answer.
    // ---------------------------------------------------------
    {
        int n = 5;
        vector<vector<int>> events = {
            {1, 0, 1}, {2, 1, 2}, {3, 2, 3}, {4, 3, 4}
        };
        for (int i = 5; i <= 10000; i++) {
            events.push_back({i, 0, 4}); // Redundant spam
        }
        mt19937 rng(99); 
        shuffle(events.begin(), events.end(), rng);
        tests.push_back({"Early Connect + 10k Noisy Late Events", n, events, 4});
    }

    // ---------------------------------------------------------
    // 14. DESCENDING TIME SORT TRAP
    // The events are perfectly sorted... backwards. 
    // Fails algorithms that assume chronological input or sort incorrectly.
    // ---------------------------------------------------------
    {
        int n = 1000;
        vector<vector<int>> events;
        for (int i = n - 1; i > 0; i--) {
            events.push_back({i * 100, i, i - 1}); // Time drops from 99900 down to 100
        }
        tests.push_back({"Strictly Descending Time Sorted Trap", n, events, 99900});
    }

    // ---------------------------------------------------------
    // 15. DUPLICATE EDGE SPAM (N=2)
    // Same two nodes pinging each other constantly.
    // The earliest valid time is hidden in the middle of the noise.
    // ---------------------------------------------------------
    {
        int n = 2;
        vector<vector<int>> events = {
            {100, 0, 1}, {500, 1, 0}, {5, 0, 1}, {1000, 1, 0}, {10, 0, 1}
        };
        tests.push_back({"Spamming Identical Edges (N=2)", n, events, 5});
    }

    // ---------------------------------------------------------
    // 16. MAX EVENTS, IGNORED NODES TRAP
    // 10,000 events happen, but they only involve nodes 0 and 1.
    // Nodes 2 through 9999 remain totally isolated.
    // ---------------------------------------------------------
    {
        int n = 10000;
        vector<vector<int>> events;
        for (int i = 0; i < 10000; i++) {
            events.push_back({i, 0, 1}); 
        }
        tests.push_back({"Max Events on Only 2 Nodes (Isolated Trap)", n, events, -1});
    }

    // ---------------------------------------------------------
    // 17. RING GRAPH WITH A LATE STRAGGLER
    // Forms a complete circle early, but leaves one node out until the end.
    // Tests if cyclic redundancies break the component counter.
    // ---------------------------------------------------------
    {
        int n = 10000;
        vector<vector<int>> events;
        for (int i = 0; i < n - 2; i++) {
            events.push_back({i + 1, i, i + 1});
        }
        events.push_back({20000, n - 2, 0});       // Closes the loop, skips n-1
        events.push_back({50000, n - 2, n - 1});   // Finally connects the straggler
        mt19937 rng(888); 
        shuffle(events.begin(), events.end(), rng);
        tests.push_back({"Ring Graph with Late Straggler", n, events, 50000});
    }

    // ---------------------------------------------------------
    // 18. THE BIPARTITE ILLUSION
    // Nodes are divided into evens and odds. They connect densely within 
    // their own groups early, but NEVER connect to each other.
    // ---------------------------------------------------------
    {
        int n = 1000;
        vector<vector<int>> events;
        for (int i = 0; i < n - 2; i += 2) {
            events.push_back({i, i, i + 2});       // Evens connect
            events.push_back({i, i + 1, i + 3});   // Odds connect
        }
        tests.push_back({"Bipartite Illusion (Two Forests, No Bridge)", n, events, -1});
    }

    // ---------------------------------------------------------
    // 19. REVERSE LINEAR GRAPH
    // Connects N-1 to N-2, then N-2 to N-3, down to 1 to 0.
    // Forces cascading root updates in DSU.
    // ---------------------------------------------------------
    {
        int n = 5000;
        vector<vector<int>> events;
        for (int i = n - 1; i > 0; i--) {
            events.push_back({(n - i) * 5, i, i - 1}); 
        }
        // Time increases as we go backwards down the chain. Max time is at the end.
        tests.push_back({"Reverse Linear Cascading Graph", n, events, (n - 1) * 5});
    }

    // ---------------------------------------------------------
    // 20. SCATTERED FOREST MERGE
    // Creates 100 isolated trees of 100 nodes each. 
    // Then merges them all together rapidly at the end.
    // ---------------------------------------------------------
    {
        int n = 10000;
        vector<vector<int>> events;
        // Build 100 trees internally
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 99; j++) {
                events.push_back({10, i * 100 + j, i * 100 + j + 1});
            }
        }
        // Bridge the 100 trees
        for (int i = 0; i < 99; i++) {
            events.push_back({1000 + i, i * 100, (i + 1) * 100});
        }
        mt19937 rng(404); 
        shuffle(events.begin(), events.end(), rng);
        // The last tree merges at T = 1000 + 98 = 1098
        tests.push_back({"Scattered Forest Bulk Merge", n, events, 1098});
    }

    // Run all test cases
    for (int i = 0; i < tests.size(); i++) {
        runTest(i + 1, tests[i]);
    }

    cout << "\n=================================================\n";
    cout << "Testing Complete.\n";
    return 0;
}




/*


Problem Title
Earliest Time of Full Connection (Google Onsite Interview)

Problem Statement
There are n nodes numbered from 0 to n - 1. Each row [time, u, v] in events records that an undirected connection between nodes u and v becomes available at time.

Connections never disappear. Determine the earliest timestamp at which every node belongs to one connected component. Events may be given in any order, and multiple events may share a timestamp. If all nodes never form a single connected component, return -1.

Examples

Example 1

Input: n = 6, events = [[20190101,0,1], [20190104,3,4], [20190107,2,3], [20190211,1,5], [20190224,2,4], [20190301,0,3], [20190312,1,2], [20190322,4,5]]

Output: 20190301

Explanation:

At 20190101, nodes 0 and 1 are connected.

At 20190104, nodes 3 and 4 are connected.

At 20190107, nodes 2 and 3 are connected.

At 20190211, nodes 1 and 5 are connected.

At 20190224, nodes 2 and 4 are already in the same component.

At 20190301, node 0 connects with node 3. At this exact timestamp, all 6 nodes finally merge into a single connected component.

Example 2

Input: n = 4, events = [[0,2,0], [1,0,1], [3,0,3], [4,1,2], [7,3,1]]

Output: 3

Explanation:

At time 0, nodes 0 and 2 connect.

At time 1, nodes 0 and 1 connect. Component is now {0, 1, 2}.

At time 3, nodes 0 and 3 connect. Component is now {0, 1, 2, 3}. The earliest time all nodes form one network is 3.

Example 3

Input: n = 3, events = [[2,0,1], [2,1,0]]

Output: -1

Explanation: Node 2 never connects to the {0, 1} component, so a full connection is never achieved.

Constraints

2 <= n <= 10^4

1 <= events.length <= 10^4

events[i].length == 3

0 <= events[i][0] <= 10^9 (the timestamp)

0 <= events[i][1], events[i][2] <= n - 1

events[i][1] != events[i][2]

events are not necessarily sorted by time.

Multiple events may occur at the same timestamp.




*/