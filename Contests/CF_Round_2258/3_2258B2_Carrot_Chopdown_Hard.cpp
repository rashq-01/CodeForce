#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    // Prefix sum array for fast bucket quantity querying
    vector<int> pref(m + 2, 0);
    for (int i = 1; i <= m; i++) {
        pref[i] = pref[i - 1] + cnt[i];
    }
    
    vector<long long> ans(m + 1, 0);
    int max_k = min(m, 18); // 2^18 > 200,000, so k > 18 is identical to k = 18

    for (int k = 1; k <= max_k; k++) {
        long long best = 0;
        long long two_k = 1LL << k;
        
        for (int L = 1; L <= m; L++) {
            long long current_ans = 0;
            int limit = m / L;
            int b_max = limit;
            
            // If the capacity 2^k is reached, we only bucket-process up to 2^k - 1
            if (two_k <= limit) {
                b_max = two_k - 1;
            }
            
            int left = L - 1;
            // Evaluates buckets B where g(B, k) = B (Meaning B < 2^k)
            for (int B = 1; B <= b_max; B++) {
                int right = min(m, left + L);
                int count = pref[right] - pref[left];
                current_ans += (long long)count * B;
                left = right;
            }
            
            // Explicitly handle bounds >= 2^k
            if (limit >= two_k) {
                long long exact_val = (long long)L * two_k;
                if (exact_val <= m) {
                    // Only exact multiples a = L * 2^k yield exactly 2^k pieces
                    int count_exact = pref[exact_val] - pref[exact_val - 1];
                    current_ans += (long long)count_exact * two_k;
                    
                    // Everything larger yields 2^k - 1 pieces because a leftover fragment is forced 
                    int count_greater = pref[m] - pref[exact_val];
                    current_ans += (long long)count_greater * (two_k - 1);
                }
            }
            
            if (current_ans > best) {
                best = current_ans;
            }
        }
        ans[k] = best;
    }
    
    // Output mapped answers for each k
    for (int k = 1; k <= m; k++) {
        if (k > max_k) {
            cout << ans[max_k] << (k == m ? "" : " ");
        } else {
            cout << ans[k] << (k == m ? "" : " ");
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}