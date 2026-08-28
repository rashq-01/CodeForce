
#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int>& transitionTime,
                   vector<int>& requestedHubs)
{
    int n = transitionTime.size();

    // prefix[i] = sum of transitionTime[0 ... i-1]
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + transitionTime[i];

    long long total = prefix[n];
    long long ans = 0;

    int curr = 1;

    for (int target : requestedHubs)
    {
        if (curr == target)
            continue;

        // Clockwise distance: curr -> target
        long long clockwise;

        if (curr < target)
        {
            // Edges curr, curr+1, ..., target-1
            clockwise = prefix[target - 1] - prefix[curr - 1];
        }
        else
        {
            // curr -> ... -> n -> 1 -> ... -> target
            clockwise =
                (prefix[n] - prefix[curr - 1])
                + prefix[target - 1];
        }

        // Counter-clockwise is simply the other way around
        long long counterClockwise = total - clockwise;

        ans += min(clockwise, counterClockwise);

        curr = target;
    }

    return ans;
}

int main()
{
    // Test 1 - Given example
    vector<int> transitionTime1 = {3, 2, 1};
    vector<int> requestedHubs1 = {1, 3, 3, 2};
    // Expected: 4

    // Test 2 - Already at the same hub
    vector<int> transitionTime2 = {5, 2, 4, 3};
    vector<int> requestedHubs2 = {1, 1, 1};
    // Expected: 0

    // Test 3 - Simple 2-hub movement
    vector<int> transitionTime3 = {5, 3};
    vector<int> requestedHubs3 = {1, 2};
    // Expected: 3

    // Test 4 - Circular route matters
    vector<int> transitionTime4 = {4, 2, 3, 1};
    vector<int> requestedHubs4 = {1, 3};
    // Expected: 5

    // Test 5 - Multiple requests
    vector<int> transitionTime5 = {2, 3, 1, 4, 2};
    vector<int> requestedHubs5 = {1, 4, 2, 5};
    // Expected: 8

    cout << solution(transitionTime1, requestedHubs1) << endl;
    cout << solution(transitionTime2, requestedHubs2) << endl;
    cout << solution(transitionTime3, requestedHubs3) << endl;
    cout << solution(transitionTime4, requestedHubs4) << endl;
    cout << solution(transitionTime5, requestedHubs5) << endl;

    return 0;
}

/*



Drone Delivery Route

You are given m hubs arranged in a circular ring. Hub 1 is adjacent to Hub m. A drone can move to either adjacent hub, and the travel time between Hub i and its neighbors is given by transitionTime[i].

The drone starts at Hub 1 and must visit all hubs in the order specified by requestedHubs.

For every consecutive pair of requested hubs, the drone can travel in either direction around the circular ring. Return the minimum total travel time required to visit all requested hubs in order.

Example
transitionTime = [3, 2, 1]
requestedHubs = [1, 3, 3, 2]


Output: 4

Explanation:

1 → 1 = 0
1 → 3 = min(3, 3 + 2) = 3
3 → 3 = 0
3 → 2 = min(1, 1 + 3) = 1

Total:


*/