#include<bits/stdc++.h>

using namespace std;


  int countPossibleWinners(vector<int> initialRewards, int n) {
    if(initialRewards.size()==1)return 1;

    int maxEl = initialRewards[0];

    for(auto& num : initialRewards){
        if(num>maxEl)maxEl = num;
    }

    int ans = 0;

    for(auto& num : initialRewards){
      if(num==maxEl){
        ans++;
      }
      else{
        if(num+n >= maxEl+n-1)ans++;
      }
      
    }

    return ans;

    
  }



int main() {

    struct TestCase {
        vector<int> rewards;
        int expected;
    };

    vector<TestCase> tests = {

        // 1. Official example
        {{1, 3, 4}, 2},

        // 2. Official example
        {{5, 7, 9, 11}, 1},

        // 3. Official example
        {{8, 10, 9}, 2},

        // 4. Single customer
        {{0}, 1},

        // 5. Single customer - maximum constraint
        {{100000}, 1},

        // 6. All equal
        {{5, 5, 5, 5, 5}, 5},

        // 7. Everyone is either max or max-1
        {{9, 10, 10, 9}, 4},

        // 8. One obvious winner
        {{1, 2, 3, 10}, 1},

        // 9. Two maximum values
        {{1, 2, 10, 10}, 2},

        // 10. Three maximum values
        {{10, 10, 10, 1, 2}, 3},

        // 11. Difference exactly 1
        // Both can tie when the smaller one wins.
        {{8, 9}, 2},

        // 12. Difference exactly 2
        // Smaller one cannot win.
        {{8, 10}, 1},

        // 13. Only 9 and 10 can win
        {{5, 7, 8, 9, 10}, 2},

        // 14. Corrected previous failing case
        {{8, 9, 9, 10}, 3},

        // 15. Very large gap
        {{0, 0, 0, 100000}, 1},

        // 16. Zeros
        {{0, 0, 1}, 3},

        // 17. Multiple values near maximum
        {{0, 1, 1, 2}, 3},

        // 18. Large values
        {{99999, 100000, 99999, 99998, 100000}, 4},

        // 19. Duplicate maximum + max-1
        {{99999, 100000, 100000, 99999}, 4},

        // 20. Corrected previous failing case
        {{1, 50, 98, 99, 100}, 2},

        // 21. Maximum and max-1 only
        {{99, 100, 99, 100, 98}, 4},

        // 22. Only one max, everyone else far below
        {{1, 1, 1, 1, 100}, 1},

        // 23. All values within 1
        {{98, 99, 98, 99, 100}, 3},

        // 24. Values differ by 2
        {{98, 100, 100}, 2},

        // 25. Maximum repeated, one max-2
        {{8, 9, 9, 9}, 4},

        // 26. Maximum repeated, max-2 and max-1
        {{7, 9, 9, 8}, 3},

        // 27. Boundary with zero
        {{0, 1}, 2},

        // 28. Zero vs 2
        {{0, 2}, 1},

        // 29. Large duplicate maximum
        {{100000, 100000, 99999, 99999, 99998}, 4},

        // 30. Mixed difficult case
        {{3, 17, 18, 19, 20, 20, 21}, 3}
    };


    int passed = 0;

    for (int tc = 0; tc < (int)tests.size(); tc++) {

        int actual = countPossibleWinners(
            tests[tc].rewards,
            tests[tc].rewards.size()
        );

        cout << "Test Case " << tc + 1 << ":\n";

        cout << "Input: [";
        for (int i = 0; i < (int)tests[tc].rewards.size(); i++) {
            cout << tests[tc].rewards[i];

            if (i + 1 < (int)tests[tc].rewards.size())
                cout << ", ";
        }
        cout << "]\n";

        cout << "Expected Output: " << tests[tc].expected << "\n";
        cout << "Real Output:     " << actual << "\n";

        if (actual == tests[tc].expected) {
            cout << "PASS\n";
            passed++;
        } else {
            cout << "FAIL\n";
        }

        cout << "-----------------------------\n";
    }

    cout << "\n";
    cout << "=============================\n";
    cout << "Passed: " << passed << "/" << tests.size() << "\n";
    cout << "Failed: " << tests.size() - passed << "/" << tests.size() << "\n";
    cout << "=============================\n";

    return 0;
}