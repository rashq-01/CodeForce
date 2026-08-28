#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <cassert>

using namespace std::chrono;
using namespace std;

vector<int> getUnfulfilledCustomers(vector<vector<int>>& req, int totalInventory){
    sort(req.begin(),req.end(),[](const vector<int>& a,const vector<int>& b){
        if(a[2] != b[2]){
            return a[2] > b[2];
        }

        return a[3]<b[3];
    });
    int i = 0;
    while(i<req.size() && totalInventory>0){
        totalInventory-=req[i][1];
        i++;
    }

    vector<int> ans;
    while(i<req.size()){
        ans.push_back(req[i][0]);
        i++;
    }

    sort(ans.begin(),ans.end());
    return ans;

}

// ==========================================
// TEST FRAMEWORK & GENERATORS
// ==========================================
struct TestCase {
    string name;
    vector<vector<int>> requests;
    int totalInventory;
    vector<int> expected;
};

void runTest(int testNum, const TestCase& tc) {
    cout << "Test " << testNum << ": " << tc.name << "... ";
    
    // Copy requests so we don't modify the original test case data
    vector<vector<int>> reqs = tc.requests;
    
    auto start = high_resolution_clock::now();
    vector<int> result = getUnfulfilledCustomers(reqs, tc.totalInventory);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(stop - start);
    
    if (result == tc.expected) {
        cout << "\033[1;32mPASSED\033[0m (" << duration.count() << " ms)\n";
    } else {
        cout << "\033[1;31mFAILED\033[0m\n";
        cout << "  Expected Size: " << tc.expected.size() << " | Output Size: " << result.size() << "\n";
        if (tc.expected.size() <= 20) {
            cout << "  Expected: ["; for(int x : tc.expected) cout << x << " "; cout << "]\n";
            cout << "  Output:   ["; for(int x : result) cout << x << " "; cout << "]\n";
        }
    }
}

int main() {
    cout << "=================================================\n";
    cout << "   UNFULFILLED CUSTOMERS - SYSTEM TEST SUITE     \n";
    cout << "=================================================\n\n";

    vector<TestCase> tests;

    // 1. Basic Example 1
    tests.push_back({"Basic Example 1", {{1, 5, 5, 0}, {2, 7, 8, 1}, {3, 7, 5, 1}, {4, 10, 3, 3}}, 18, {4}});
    
    // 2. Basic Example 2
    tests.push_back({"Basic Example 2", {{1, 2, 5, 0}, {2, 5, 10, 2}, {3, 3, 10, 1}, {4, 4, 2, 3}, {5, 2, 5, 1}}, 8, {1, 4, 5}});

    // 3. Partial Fulfillment Trap
    // Inventory is 11. C1 gets 10. C2 wants 10, gets 1 (Partial). C3 gets 0.
    // Result should ONLY be C3. If logic is wrong, C2 might accidentally be included.
    tests.push_back({"Partial Fulfillment Trap", 
        {{1, 10, 10, 1}, {2, 10, 9, 2}, {3, 10, 8, 3}}, 11, {3}});

    // 4. Absolute Zero Inventory
    tests.push_back({"Zero Inventory Baseline", 
        {{1, 5, 10, 1}, {2, 5, 10, 2}, {3, 5, 10, 3}}, 0, {1, 2, 3}});

    // 5. MAX CONSTRAINTS: 10^5 requests, exact tie-breaker hell
    {
        int N = 100000;
        vector<vector<int>> reqs(N);
        vector<int> expected;
        for (int i = 0; i < N; i++) {
            // [customerId, quantity, bidAmount, timestamp]
            reqs[i] = {i + 1, 10, 100, N - i}; // Everyone bids 100. Timestamps are reversed!
            if (i < 50000) expected.push_back(i + 1); // The ones with later timestamps get 0
        }
        // Total inventory 500,000. Everyone wants 10. Exactly 50,000 people fulfilled.
        tests.push_back({"Max Limits 10^5 (Tie-Breaker Hell)", reqs, 500000, expected});
    }

    // 6. MAX CONSTRAINTS: Reverse Priority Stress
    {
        int N = 100000;
        vector<vector<int>> reqs(N);
        vector<int> expected;
        for (int i = 0; i < N; i++) {
            // Bids are increasing. This means the array is sorted in the EXACT OPPOSITE
            // of the required priority, forcing std::sort to do maximum swaps.
            reqs[i] = {i + 1, 1, i + 1, i}; 
            if (i < 50000) expected.push_back(i + 1); 
        }
        tests.push_back({"Max Limits 10^5 (Reverse Sorted Stress)", reqs, 50000, expected});
    }

    // 7. MAX CONSTRAINTS: The "Minus One" Trap
    {
        int N = 100000;
        vector<vector<int>> reqs(N);
        for (int i = 0; i < N; i++) {
            reqs[i] = {i + 1, 10, 50, i}; 
        }
        // Total requested is 1,000,000.
        // We set inventory to 999,991. 
        // 99,999 people get 10. The last person gets 1. NO ONE gets 0!
        tests.push_back({"Max Limits 10^5 (Minus One Trap)", reqs, 999991, {}});
    }

    // 8. Timestamp Max Limit (10^9) 
    tests.push_back({"Max Timestamp Limit (10^9)", 
        {{1, 10, 5, 1000000000}, {2, 10, 5, 999999999}}, 10, {1}});

    // 9. All Random Bids & Times
    {
        int N = 100000;
        vector<vector<int>> reqs(N);
        vector<int> expected;
        for (int i = 0; i < N; i++) {
            // Alternating extreme bids
            reqs[i] = {i + 1, 100, (i % 2 == 0 ? 10000 : 1), i}; 
            if (i % 2 != 0) expected.push_back(i + 1);
        }
        // Inventory enough for exactly all the even IDs (high bidders)
        tests.push_back({"Alternating Max/Min Bids (10^5)", reqs, 5000000, expected});
    }

    // Run all tests
    for (int i = 0; i < tests.size(); i++) {
        runTest(i + 1, tests[i]);
    }

    cout << "\n=================================================\n";
    cout << "Testing Complete.\n";
    return 0;
}