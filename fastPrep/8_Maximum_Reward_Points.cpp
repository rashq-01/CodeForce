
#include<bits/stdc++.h>

using namespace std;


long long getMaximumRewardPoints(int k, vector<int>& reward1,vector<int>& reward2){
    int n = reward1.size();

    long long totalReward = 0;
    vector<long long> diff(n);
    
    for(int i=0;i<n;i++){
        totalReward += reward2[i];

        diff[i] = reward1[i] - reward2[i];
    }

    sort(diff.rbegin(),diff.rend());

    for(int i=0;i<k;i++){
        totalReward += diff[i];
    }

    return totalReward;
}


// Helper to build large test arrays dynamically
vector<int> generateArray(int size, int val) {
    return vector<int>(size, val);
}

vector<int> generateAlternating(int size, int val1, int val2) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) arr[i] = (i % 2 == 0) ? val1 : val2;
    return arr;
}

// Struct to define a Test Case
struct TestCase {
    string name;
    int k;
    vector<int> reward_1;
    vector<int> reward_2;
    int expected;
};

int main() {
    vector<TestCase> tests = {
        // Basic Problem Examples
        {"Example 1", 3, {5, 4, 3, 2, 1}, {1, 2, 3, 4, 5}, 21},
        
        // Edge Cases
        {"Intern 1 does 0 tasks (k=0)", 0, {10, 20, 30}, {1, 2, 3}, 6},
        {"Intern 1 does ALL tasks (k=n)", 3, {10, 20, 30}, {1, 2, 3}, 60},
        {"Intern 1 is strictly worse but must work", 2, {1, 1, 1}, {100, 100, 100}, 102},

        // HARD CONSTRAINTS (Max Inputs & Tricky distributions)
        {
            "Hard 1: Max Constraint Limits (Both max values)", 
            50000, 
            generateArray(100000, 10000), // 10^5 elements of 10,000
            generateArray(100000, 10000), // 10^5 elements of 10,000
            1000000000 // 10^9 (Safely fits in 32-bit signed int)
        },
        {
            "Hard 2: Massive Array, Intern 1 is terrible but must do K tasks", 
            50000, 
            generateArray(100000, 1),     // 10^5 elements of 1
            generateArray(100000, 10000), // 10^5 elements of 10,000
            500050000  // 50,000 * 10000 + 50,000 * 1
        },
        {
            "Hard 3: Alternating Traps", 
            50000, 
            generateAlternating(100000, 10000, 1),
            generateAlternating(100000, 1, 10000),
            1000000000 // Best scenario: Intern 1 takes all 10,000s, Intern 2 takes all 10,000s
        }
    };

    int passed = 0;
    cout << "=======================================\n";
    cout << "      MAXIMUM REWARD POINTS - TESTS    \n";
    cout << "=======================================\n\n";

    for (int i = 0; i < tests.size(); i++) {
        int result = getMaximumRewardPoints(tests[i].k, tests[i].reward_1, tests[i].reward_2);
        
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




/*





Maximum Reward Points

● Medium

Microsoft logo
Microsoft
NEW GRAD
INTERN

OA

Problem statement
Two interns are assigned to complete a total of n tasks. Each task must be completed by exactly one of them. For task i, the first intern earns reward_1[i] points and the second intern earns reward_2[i] points.

The first intern must complete exactly k tasks, which may be any k of the n tasks. The second intern completes the remaining tasks. Return the maximum possible combined reward points.

Function
getMaximumRewardPoints(k: int, reward_1: int[], reward_2: int[]) → int
Examples
Example 1
k = 3
reward_1 = [5, 4, 3, 2, 1]
reward_2 = [1, 2, 3, 4, 5]
return = 21
The first intern completes the first three tasks and earns 5 + 4 + 3 points. The second intern completes the remaining two tasks and earns 4 + 5 points. Their combined reward is 5 + 4 + 3 + 4 + 5 = 21, which is the maximum possible.

Constraints
1 ≤ n ≤ 10^5
0 ≤ k ≤ n
1 ≤ reward_1[i] ≤ 10^4
1 ≤ reward_2[i] ≤ 10^4






*/