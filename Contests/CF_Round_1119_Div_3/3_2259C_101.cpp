#include <bits/stdc++.h>
using namespace std;

void fun() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    vector<int> ones;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            ones.push_back(i);
        }
    }

    pair<int, int> ans = {-1, -1};
    int maxLen = 0;


    if (ones.empty()) {
        int l = -1, r = -1;


        for (int i = 0; i < n; i++) {
            if (arr[i] == -1) {
                l = i;
                break;
            }
        }


        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == -1) {
                r = i;
                break;
            }
        }

        if (l != -1 && r != -1) {
            ans = {l, r};
        }
    }
    else {
        int first = ones.front();

        for (int i = 0; i < first; i++) {
            if (arr[i] == 0) continue;

            if (arr[i] == -1) {
                int len = first - i + 1;

                if (len > maxLen) {
                    maxLen = len;
                    ans = {i, first};
                }

                break;
            }
        }

        for (int k = 1; k < (int)ones.size(); k++) {
            int l = ones[k - 1];
            int r = ones[k];

            int len = r - l + 1;

            if (len > maxLen) {
                maxLen = len;
                ans = {l, r};
            }
        }
        int last = ones.back();

        for (int i = n - 1; i > last; i--) {
            if (arr[i] == 0) continue;

            if (arr[i] == -1) {
                int len = i - last + 1;

                if (len > maxLen) {
                    maxLen = len;
                    ans = {last, i};
                }

                break;
            }
        }
    }

    if (ans.first != -1) {
        arr[ans.first] = 1;
        arr[ans.second] = 1;
    }

    // Every other -1 should be 0
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            arr[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i + 1 == n ? '\n' : ' ');
    }
}

int main() {

    int T;
    cin >> T;

    while (T--) {
        fun();
    }

    return 0;
}