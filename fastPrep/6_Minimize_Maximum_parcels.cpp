#include<bits/stdc++.h>

using namespace std;

long long minimizeMaximumParcels(vector<int>& packages,long long extra){
    int n = packages.size();

    long long maxEl = 0;
    for(auto& pck : packages) maxEl = max(maxEl,(long long)pck);

    for(auto& pck : packages){
        extra -= (maxEl-pck);

        if(extra<=0)return maxEl;
    }

    long long ext = (extra + n -1)/n;

    return maxEl + ext;
}

// Helper to build large test arrays dynamically
vector<int> generateArray(int size, int default_val, int single_outlier_idx = -1, int outlier_val = 0) {
    vector<int> arr(size, default_val);
    if (single_outlier_idx != -1) arr[single_outlier_idx] = outlier_val;
    return arr;
}

vector<int> generateIncremental(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) arr[i] = i + 1;
    return arr;
}

// Struct to define a Test Case
struct TestCase {
    string name;
    vector<int> packages;
    long long extra_packages;
    long long expected;
};

int main() {
    vector<TestCase> tests = {
        // Basic Problem Examples
        {"Example 1", {7, 5, 1, 9, 1}, 25, 10},
        {"Example 2", {1, 2, 3}, 3, 3},
        {"Example 3", {1}, 3, 4},
        
        // Tricky Small Cases
        {"Exact Gap Fill", {10, 1}, 9, 10},
        {"One Above Gap Fill", {10, 1}, 10, 11},
        {"Massive Gap, Small Extra", {1000000000, 1}, 5, 1000000000},
        {"All Identical, Awkward Remainder", {5, 5, 5}, 7, 8},

        // HARD CONSTRAINTS (Max Inputs)
        {
            "Hard 1: Max Single Element", 
            {1}, 
            1000000000000000LL, // 10^15
            1000000000000001LL
        },
        {
            "Hard 2: Massive Array, All Max Value", 
            generateArray(100000, 1000000000), // 10^5 elements of 10^9
            1000000000000000LL,                // 10^15 extra
            11000000000LL                      // 10^9 + 10^10
        },
        {
            "Hard 3: Massive Array, One Huge Max, Rest Min", 
            generateArray(100000, 1, 0, 1000000000), // [10^9, 1, 1, ... 1]
            1000000000000000LL, 
            10000010001LL
        },
        {
            "Hard 4: Incremental Massive Array", 
            generateIncremental(100000),       // [1, 2, ..., 100000]
            100000000000000LL,                 // 10^14 extra
            1000050001LL
        }
    };

    int passed = 0;
    cout << "=======================================\n";
    cout << "    MINIMIZE MAXIMUM PARCELS - TESTS   \n";
    cout << "=======================================\n\n";

    for (int i = 0; i < tests.size(); i++) {
        long long result = minimizeMaximumParcels(tests[i].packages, tests[i].extra_packages);
        
        cout << "Test " << i + 1 << ": " << tests[i].name << "\n";
        cout << "Expected : " << tests[i].expected << "\n";
        cout << "Output   : " << result << "\n";
        
        if (result == tests[i].expected) {
            cout << "Status   : \033[1;32m✅ PASS\033[0m\n\n";
            passed++;
        } else {
            cout << "Status   : \033[1;31m❌ FAIL\033[0m\n\n";
        }
    }

    cout << "=======================================\n";
    cout << "Results: " << passed << " / " << tests.size() << " Passed\n";
    cout << "=======================================\n";

    return 0;
}