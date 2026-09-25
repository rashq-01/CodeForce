#include<bits/stdc++.h>

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// ==========================================
// PASTE YOUR ALGORITHM HERE
// ==========================================


int getDistinctPairs(vector<int>& nums , long long target){
    int n = nums.size();

    unordered_set<int> seen;
    unordered_set<int> counted;

    int ans = 0;

    for(int x : nums){
        long long comp = target - x;

        if(comp > 1000000000LL || comp<0){
            seen.insert(x);
            continue;
        }

        if(seen.count(comp) && !counted.count(x)){
            ans++;
            counted.insert(x);
            counted.insert(comp);
        }

        seen.insert(x);
    }

    return ans;
}

// ==========================================
// TEST FRAMEWORK
// ==========================================
struct TestCase {
    string name;
    vector<int> stocksProfit;
    long long target;
    int expected;
};

void runTest(int testNum, const TestCase& tc) {
    cout << "Test " << testNum << " [" << tc.name << "]... ";
    
    vector<int> arr = tc.stocksProfit;
    
    auto start = high_resolution_clock::now();
    int result = getDistinctPairs(arr, tc.target);
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
    cout << "  BRUTAL TEST SUITE - DISTINCT INVESTMENT PAIRS  \n";
    cout << "=================================================\n\n";

    vector<TestCase> tests;

    // ---------------------------------------------------------
    // 1. SAMPLE CASE (From Problem Description)
    // ---------------------------------------------------------
    {
        vector<int> p = {5, 7, 9, 13, 11, 6, 6, 3, 3};
        tests.push_back({"Sample Case", p, 12, 3});
    }

    // ---------------------------------------------------------
    // 2. IDENTICAL HALVES TRAP (Sufficient Count)
    // Needs exactly two identical values to form the target.
    // ---------------------------------------------------------
    {
        vector<int> p = {6, 6, 6, 6, 6};
        tests.push_back({"Identical Halves (Sufficient)", p, 12, 1});
    }

    // ---------------------------------------------------------
    // 3. IDENTICAL HALVES TRAP (Insufficient Count)
    // Only one value exists, so it cannot pair with itself.
    // ---------------------------------------------------------
    {
        vector<int> p = {12, 24, 36};
        tests.push_back({"Identical Halves (Insufficient)", p, 24, 0});
    }

    // ---------------------------------------------------------
    // 4. MULTIPLE REDUNDANT PAIRS TRAP
    // High duplication of valid distinct pairs.
    // ---------------------------------------------------------
    {
        vector<int> p = {2, 2, 2, 8, 8, 8, 4, 4, 6, 6, 4, 6};
        tests.push_back({"High Duplication Spam", p, 10, 3}); 
        // Valid Pairs: (2,8), (4,6). Wait, (5,5) is not possible here. Total = 2.
        tests.back().expected = 2;
    }

    // ---------------------------------------------------------
    // 5. MAX BOUNDARY TARGET TRAP (Target requires 64-bit Int)
    // ---------------------------------------------------------
    {
        vector<int> p = {1000000000, 1000000000}; // Max values
        tests.push_back({"Max Boundary Target Overflow (2*10^9)", p, 2000000000LL, 1});
    }

    // ---------------------------------------------------------
    // 6. IMPOSSIBLE TARGET TRAP
    // Target is larger than the maximum possible sum of any two elements.
    // ---------------------------------------------------------
    {
        vector<int> p = {1000000000, 1000000000, 999999999};
        tests.push_back({"Impossible Target (Exceeds Max Sum)", p, 3000000000LL, 0});
    }

    // ---------------------------------------------------------
    // 7. ZERO TARGET TRAP
    // ---------------------------------------------------------
    {
        vector<int> p = {0, 0, 0, 0, 5, -5}; // Problem says 0 <= stocksProfit[i], so no negatives.
        vector<int> valid_p = {0, 0, 0, 0, 1, 2};
        tests.push_back({"Zero Target with Multiple Zeros", valid_p, 0, 1});
    }

    // ---------------------------------------------------------
    // 8. NO VALID PAIRS
    // ---------------------------------------------------------
    {
        vector<int> p = {1, 2, 3, 4, 5};
        tests.push_back({"No Valid Pairs Possible", p, 100, 0});
    }

    // ---------------------------------------------------------
    // 9. DENSE ARRAY STRESS TEST (N = 500,000)
    // Sequential numbers where exactly half form pairs.
    // Tests O(N^2) Time Limit Exceeded (TLE) failures.
    // ---------------------------------------------------------
    {
        int N = 500000;
        vector<int> p(N);
        for (int i = 0; i < N; i++) p[i] = i; 
        // Pairs summing to 500000: (1,499999), (2,499998) ... (249999, 250001)
        tests.push_back({"Dense Sequential Stress Test (N=500k)", p, 500000LL, 249999});
    }

    // ---------------------------------------------------------
    // 10. SPARSE MATCH STRESS TEST (N = 500,000)
    // Enormous array of duplicates. Only ONE unique pair exists.
    // Tests if set/map handles rapid collision overwrites efficiently.
    // ---------------------------------------------------------
    {
        int N = 500000;
        vector<int> p(N);
        for (int i = 0; i < N; i++) {
            p[i] = (i % 2 == 0) ? 10 : 20;
        }
        tests.push_back({"Sparse Match Massive Duplicates (N=500k)", p, 30LL, 1});
    }

    // ---------------------------------------------------------
    // 11. ISOLATED NEEDLES IN HAYSTACK (N = 500,000)
    // Array is full of zeros, but two elements at opposite ends form the target.
    // ---------------------------------------------------------
    {
        int N = 500000;
        vector<int> p(N, 0);
        p[0] = 500000000;
        p[N - 1] = 500000000;
        tests.push_back({"Isolated Needles (N=500k)", p, 1000000000LL, 1});
    }

    // ---------------------------------------------------------
    // 12. SINGLE ELEMENT EDGE CASE (N = 1)
    // Constraints say 1 <= N <= 5*10^5. Must not segfault on n=1.
    // ---------------------------------------------------------
    {
        vector<int> p = {100};
        tests.push_back({"Single Element Trap (N=1)", p, 100LL, 0});
    }

    // ---------------------------------------------------------
    // 13. EXACTLY ONE OFF TRAP
    // Elements are exactly 1 unit away from forming the target.
    // ---------------------------------------------------------
    {
        vector<int> p = {10, 11, 12, 13, 14};
        // Target is 30. No pairs exist because the largest possible sum is 27.
        tests.push_back({"Missing Exact Counterpart", p, 30LL, 0});
    }

    // ---------------------------------------------------------
    // 14. EXTREME SHUFFLED STRESS TEST (N = 500,000)
    // Ensures candidates sorting the array don't rely on pre-sorted input.
    // ---------------------------------------------------------
    {
        int N = 500000;
        vector<int> p(N);
        for(int i = 0; i < N; i++) {
            p[i] = i % 1000; // Values 0 to 999 duplicated 500 times each
        }
        mt19937 rng(42); 
        shuffle(p.begin(), p.end(), rng);
        // Target 1000. Unique pairs: (1,999), (2,998) ... (499, 501), (500,500)
        tests.push_back({"Extreme Shuffled Clusters (N=500k)", p, 1000LL, 500});
    }

    // ---------------------------------------------------------
    // 15. ALL IDENTICAL ZEROES (N = 500,000)
    // Massive array of zeroes where target is also zero.
    // ---------------------------------------------------------
    {
        int N = 500000;
        vector<int> p(N, 0);
        tests.push_back({"All Identical Zeroes (N=500k)", p, 0LL, 1});
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

Get Distinct Pairs

Difficulty: Easy
Company/Stage: Amazon — Intern / New Grad OA

Problem Statement
A financial strategist at Amazon Web Services (AWS) is analyzing a collection of profitable investments, each represented by an integer array. Every value in the array indicates the annual gain of a particular investment. The strategist's goal is to identify all unique investment pairs whose combined annual returns exactly match a given target value.

Unique pairs are defined as combinations of values that are distinct. (i.e., if multiple pairs have the exact same values, they are considered duplicate versions of the same pair and should only be counted once).

Given the array of gains, compute the number of unique investment pairs whose sum equals the specified target return.

Function Description
Complete the function getDistinctPairs.

getDistinctPairs has the following parameter(s):

int stocksProfit[n]: an array of integers representing each investment’s yearly gain

int target: an integer denoting the targeted combined return

Returns

int: the total number of unique pairs that meet the target return

Constraints

1 <= n <= 5 * 10^5

0 <= stocksProfit[i] <= 10^9

0 <= target <= 5 * 10^9

Examples

Example 1
Input:

Plaintext
stocksProfit = [5, 7, 9, 13, 11, 6, 6, 3, 3]
target = 12
Output:
3

Explanation:
There are four pairs whose combined gains equal the target return of 12. However, since the array includes duplicate values of 3, there are two versions of the pair (9, 3): one between positions 2 and 7, and another between positions 2 and 8. But only one of these can be counted to maintain uniqueness. Therefore, the valid and unique pairs are:

(5, 7)

(9, 3)

(6, 6)

The total number of unique valid pairs is 3. We return 3.

*/