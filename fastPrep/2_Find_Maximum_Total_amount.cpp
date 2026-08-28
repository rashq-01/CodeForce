#include<bits/stdc++.h>

using namespace std;

struct TestCase {
    vector<vector<long long>> segments;
    long long k;
    long long expected;
};

int getVal(vector<vector<long long>>& segment, int target){
    int n = segment.size();


    int left = 0;
    int right = n-1;

    while(left<=right){
        int mid = left + (right-left)/2;

        if(target>=segment[mid][0] && target<=segment[mid][1]){
            return segment[mid][2];
        }
        else if(target<segment[mid][0]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return 0;

}

long long maxTotalAmount(vector<vector<long long>>& segment, long long k){

    sort(segment.begin(),segment.end());

    int n = segment.back()[1];

    long long maxSum = 0;
    long long currSum = 0;
    int i = 1;
    while(i<=k){
        currSum += getVal(segment,i);
        if(i==k) maxSum = max(maxSum,currSum);

        i++;
    }
    for(int left=1,right=i;right<=n;right++){
        currSum+=getVal(segment,right);
        currSum-=getVal(segment,left);
        maxSum = max(maxSum,currSum);
        left++;
    }

    return maxSum;

}

int main(){

    vector<TestCase> tests = {

        // 1. Example from the problem
        {
            {{1,4,2}, {6,6,5}, {7,7,7}, {9,10,1}},
            5,
            16
        },

        // 2. Single segment, k exactly equals segment length
        {
            {{1,5,10}},
            5,
            50
        },

        // 3. Single segment, k smaller than segment
        // Bags: 10 10 10 10 10
        // Best 3 = 30
        {
            {{1,5,10}},
            3,
            30
        },

        // 4. Single segment, k = 1
        {
            {{1,5,10}},
            1,
            10
        },

        // 5. Gaps between segments
        // Bags: 5 5 0 0 10 10
        // k=3 => 0+10+10 = 20
        {
            {{1,2,5}, {5,6,10}},
            3,
            20
        },

        // 6. Best window contains two segments
        // Bags: 5 5 0 10 10
        // k=4
        // [2..5] = 5+0+10+10 = 25
        {
            {{1,2,5}, {4,5,10}},
            4,
            25
        },

        // 7. Best window is completely inside a large segment
        {
            {{1,10,7}},
            4,
            28
        },

        // 8. k larger than total represented range
        // Bags 1..5 = 3 each, k=10
        // Only 5 bags contain money
        {
            {{1,5,3}},
            10,
            15
        },

        // 9. Many gaps
        // 5,0,0,10,0,20
        // k=3 => 0+10+0 = 10 OR 10+0+20 = 30
        {
            {{1,1,5}, {4,4,10}, {6,6,20}},
            3,
            30
        },

        // 10. k=1 with different segment values
        {
            {{1,3,2}, {5,5,100}, {8,10,7}},
            1,
            100
        },

        // 11. Optimal window starts in a gap
        // Bags: 10 10 0 0 20 20
        // k=4 => 0+0+20+20 = 40
        {
            {{1,2,10}, {5,6,20}},
            4,
            40
        },

        // 12. Optimal window ends in a gap
        // 10 10 20 20 0
        // k=5 = 60
        {
            {{1,2,10}, {3,4,20}},
            5,
            60
        },

        // 13. Several segments contribute to answer
        // 5 5 0 10 10 0 20 20
        // k=6
        // [3..8] = 0+10+10+0+20+20 = 60
        {
            {{1,2,5}, {4,5,10}, {7,8,20}},
            6,
            60
        },

        // 14. Segment of length 1
        {
            {{100,100,50}},
            1,
            50
        },

        // 15. Huge gap
        {
            {{1,2,10}, {1000000,1000002,20}},
            3,
            60
        },

        // 16. Huge gap, but k cannot bridge it
        {
            {{1,2,10}, {1000000,1000002,20}},
            2,
            40
        },

        // 17. Adjacent segments
        // If non-intersecting segments can be adjacent:
        // 1 1 2 2 2
        // k=4 => 7
        {
            {{1,2,1}, {3,5,2}},
            4,
            7
        },

        // 18. Multiple isolated high-value bags
        // 1, 100, 1, 100, 1
        // k=3 => 100+1+100 = 201
        {
            {{1,1,1}, {2,2,100}, {3,3,1}, {4,4,100}, {5,5,1}},
            3,
            201
        },

        // 19. High value surrounded by zeros
        // ... 1 1 1 100 1 1 1 ...
        // k=3 => 102
        {
            {{1,3,1}, {4,4,100}, {5,7,1}},
            3,
            102
        },

        // 20. k covers everything with some zeros
        // 10 10 0 0 20
        // k=5 => 40
        {
            {{1,2,10}, {5,5,20}},
            5,
            40
        },

        // 21. All bags have same amount
        {
            {{1,100,5}},
            10,
            50
        },

        // 22. k=1 and all segments are length 1
        {
            {{1,1,3}, {5,5,8}, {10,10,2}, {20,20,15}},
            1,
            15
        },

        // 23. Optimal answer from a combination of 3 segments
        // 5 + 10 + 20 = 35
        {
            {{1,1,5}, {3,3,10}, {5,5,20}},
            5,
            35
        },

        // 24. One massive segment plus another segment
        // k=5
        // Best inside first segment = 50
        {
            {{1,10,10}, {20,20,100}},
            5,
            100
        },

        // 25. Large isolated value dominates
        {
            {{1,100,1}, {1000,1000,1000}},
            10,
            1000
        },

        // 26. k=2, adjacent high values
        {
            {{1,1,5}, {2,2,100}, {3,3,200}},
            2,
            300
        },

        // 27. k=3, best is middle section
        // 1 100 100 100 1
        {
            {{1,1,1}, {2,4,100}, {5,5,1}},
            3,
            300
        },

        // 28. Large gap with k just enough to bridge it
        // bag 1 = 10, bag 5 = 20
        // k=5 => 30
        {
            {{1,1,10}, {5,5,20}},
            5,
            30
        },

        // 29. Large gap with k not enough
        {
            {{1,1,10}, {5,5,20}},
            3,
            20
        },

        // 30. Optimal window contains a partial first segment
        // 5 5 5 10 10
        // k=3 => 30
        {
            {{1,3,5}, {4,5,10}},
            3,
            25
        }
    };


    // Run your solution against every test case.
    for (int tc = 0; tc < tests.size(); tc++) {

        auto segments = tests[tc].segments;
        long long k = tests[tc].k;
        long long expected = tests[tc].expected;

        // ----------------------------------------------------
        // Call YOUR solution here.
        // Example:
        //
        // long long actual = solve(segments, k);
        // ----------------------------------------------------

        // For demonstration:
        long long actual = maxTotalAmount(segments,k);

        cout << "Test Case " << tc + 1 << "\n";
        cout << "Expected: " << expected << "\n";
        cout << "Actual:   " << actual << "\n";

        if (actual == expected)
            cout << "PASS\n";
        else
            cout << "FAIL\n";

        cout << "-------------------------\n";
    }

    return 0;
}








/*



Problem · Prefix Sum
Find Maximum Total Amount (SDE I, Fungible :)
● Medium
Amazon logo
Amazon
NEW GRAD
FULLTIME
OA
See Amazon hiring insights
Problem statement
In Amazon's financial team, an analyst is dealing with an infinite number of bags arranged in a line, each numbered from 1 to infinity. The task is to gather information about the amount of money in these bags, presented in the form of continuous segments. The objective is to select consecutive bags in such a way that the total amount of money in these bags is maximized.

The continuous segments provided to represent the amount of money in each bag do not intersect. Additionally, any bag included within a segment contains some amount of money, while bags not included in any segment are considered to have zero money.

The problem statement continues
Pro
Examples
Example 1
segment = [[1, 4, 2], [6, 6, 5], [7, 7, 7], [9, 10, 1]]
k = 5
return = 16
The amount of money in each bag is:

Bag	1	2	3	4	5	6	7	8	9	10
Money	2	2	2	2	0	5	7	0	1	1
All other bags have zero money.

Let's try different consecutive bags of size k:

Bags	Total Money
[1 - 5]	2 + 2 + 2 + 2 + 0 = 8
[2 - 6]	2 + 2 + 2 + 0 + 5 = 11
[3 - 7]	2 + 2 + 0 + 5 + 7 = 16
[4 - 8]	2 + 0 + 5 + 7 + 0 = 14
[5 - 9]	0 + 5 + 7 + 0 + 1 = 13
[6 - 10]	5 + 7 + 0 + 1 + 1 = 14
The subsegment starting from the third bag and ending at the seventh bag has the maximum total amount of money, hence the answer is 16.



*/