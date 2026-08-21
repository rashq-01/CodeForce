
#include<bits/stdc++.h>

using namespace std;

string cpy(char c,int S){
    string ans = "";
    for(int i=0;i<S;i++)ans.push_back(c);

    return ans;
}

string makeAlphabeticallySmallestPalindrome(string s){
    int n = s.size();

    vector<int> mp(26,0);

    for(auto& ch : s){
        mp[ch-'a']++;
    }

    int i=0;
    int j = 25;
    char ch;
    bool status = false;
    while(i<=j){
        while(i<26 && mp[i]%2==0)i++;
        while(j>=0 && mp[j]%2==0)j--;
        if(i<j){
            mp[i]++;
            mp[j]--;
        }
        else if(i==j){
            ch = char('a'+i);
            status = true;
            break;
        }
        i++;
        j--;
    }

    string ans = "";
    for(int i=0;i<26;i++){
        if(mp[i]/2 != 0){
            ans = ans + cpy('a'+i,mp[i]/2);
        }
    }
    string rev = ans;
    reverse(rev.begin(),rev.end());

    if(status){
        string finalAns = ans;
        finalAns.push_back(ch);
        finalAns += rev;
        return finalAns;
    }

    return ans+rev;


}



// Helper function to truncate large strings for console printing
string truncate(const string& str, int maxLength = 40) {
    if (str.length() <= maxLength) return str;
    return str.substr(0, 20) + "..." + str.substr(str.length() - 20);
}

// Struct to hold test case data
struct TestCase {
    string s;
    string expected;
    string desc;
};

int main() {
    // Define standard test cases
    vector<TestCase> test_cases = {
        {"azzzbbb", "abzbzba", "Example 1: Basic odd frequencies merger"},
        {"cbaabc", "abccba", "No changes needed: Already can form a palindrome, just needs sorting"},
        {"abcdef", "abccba", "All distinct (Even length): Requires merging largest to smallest"},
        {"edcba", "abcba", "All distinct (Odd length): Center character tie-breaking"},
        {"a", "a", "Edge Case: Single character"},
        {"zaaxy", "axyxa", "Tricky: Odds are x, y, z. Merging z->x gives smallest palindrome"},
        {"azyxz", "azxza", "Tricky: Odds are a, x, y. Merging y->a gives smallest palindrome"},
        {"aaabc", "aabaa", "Tricky: Merging odd 'c' into already odd 'a' is better than 'c' into 'b'"},
        {"aabbcde", "abcdcba", "Multiple odds in odd-length string. Merging e->c is best"},
        {"zzxxyy", "xyzzyx", "Even frequencies but large letters: Ensure outer letters are smallest"},
        {"abcdefghijklmnopqrstuvwxyz", "abcdefghijklmmlkjihgfedcba", "Alphabet: 26 distinct odds, exactly 13 changes needed"}
    };

    // Add the large performance test case dynamically
    string large_s = string(50000, 'a') + string(50000, 'b');
    string large_expected = string(25000, 'a') + string(50000, 'b') + string(25000, 'a');
    test_cases.push_back({large_s, large_expected, "Performance/Large constraint test: 10^5 length, no changes needed"});

    int passed_count = 0;
    int total_count = test_cases.size();

    cout << "============================================================\n";
    cout << "🚀 RUNNING TESTS...\n";
    cout << "============================================================\n";

    for (int i = 0; i < total_count; ++i) {
        string s = test_cases[i].s;
        string expected = test_cases[i].expected;
        string desc = test_cases[i].desc;

        // Call your function
        string actual = makeAlphabeticallySmallestPalindrome(s);

        // Check if actual matches expected
        bool is_pass = (actual == expected);
        if (is_pass) passed_count++;

        string status = is_pass ? "✅ PASS" : "❌ FAIL";

        // Print results (truncating huge outputs)
        cout << "Test " << (i + 1) << ": " << desc << "\n";
        cout << "Input:    " << truncate(s) << "\n";
        cout << "Expected: " << truncate(expected) << "\n";
        cout << "Actual:   " << truncate(actual) << "\n";
        cout << "Status:   " << status << "\n";
        cout << "------------------------------------------------------------\n";
    }

    // Summary Generation
    cout << "============================================================\n";
    cout << "📊 TEST SUMMARY\n";
    cout << "============================================================\n";
    cout << "Total Cases : " << total_count << "\n";
    cout << "Passed      : " << passed_count << "\n";
    cout << "Failed      : " << (total_count - passed_count) << "\n";

    if (passed_count == total_count) {
        cout << "\n🏆 AMAZING JOB! All test cases passed.\n";
    } else {
        cout << "\n⚠️ Keep tweaking! Some test cases failed.\n";
    }

    return 0;
}

/*



Alphabetically Smallest Palindrome
Learn this problem
● Medium
Microsoft
NEW GRAD
INTERN
OA
See Microsoft hiring insights
Problem statement
A palindrome reads the same from either direction; for example, ada is a palindrome. You are given a string s of lowercase English letters.

Change the fewest letters possible so that the characters of s can be rearranged to form a palindrome. If multiple palindromes require the same minimum number of changes, return the alphabetically smallest one.

Function
makeAlphabeticallySmallestPalindrome(s: String) → String
Examples
Example 1
s = "azzzbbb"
return = "abzbzba"
Optimally, change one z to a to get aazzbbb. These letters can be rearranged to form abzbzba, which is the alphabetically smallest palindrome possible after one change.

Constraints
1 ≤ s.length ≤ 3 × 10^5
s consists of lowercase English letters only.




*/