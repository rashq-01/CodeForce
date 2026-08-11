#include <bits/stdc++.h>
using namespace std;

int getWays(const string& s, int start) {
    int first = -1;
    int firstPos = -1;

    for (int i = start; i < (int)s.size(); i += 2) {
        if (s[i] == '?')
            continue;

        int cur = s[i] - '0';

        if (first == -1) {
            first = cur;
            firstPos = i;
        } 
        else {
            int steps = (i - firstPos) / 2;

            int expected = first ^ (steps % 2);

            if (cur != expected)
                return 0;
        }
    }

    if (first == -1)
        return 2;

    return 1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >>n;
        string s;
        cin >> s;

        int evenWays = getWays(s, 0);
        int oddWays = getWays(s, 1);

        cout << evenWays * oddWays << '\n';
    }

    return 0;
}