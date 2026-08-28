#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int mid = n / 2;
    long long cur = a[mid];

    for (int i = mid + 1; i < n; i++) {
        long long cnt = i - mid;
        long long diff = a[i] - cur;
        long long cost = diff * cnt;

        if (cost > k) {
            cout << cur + k / cnt << '\n';
            return 0;
        }

        k -= cost;
        cur = a[i];
    }

    // All elements from median to the end are now at 'cur'
    cur += k / (n - mid);

    cout << cur << '\n';

    return 0;
}