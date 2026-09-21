#include<bits/stdc++.h>

using namespace std;

const int MAXA = 200005;
vector<int> primes[MAXA];
long long dp[MAXA];

void precompute(){
    for(int i=2;i<MAXA;i++){
        if(primes[i].empty()){
            for(int j=i;j<MAXA;j+=i){
                primes[j].push_back(i);
            }
        }
    }
}



void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=k;i++){
        dp[i] = 0;
    }

    for(int i=k+1;i<=n;i++){
        long long minOps = -1;

        for(int p : primes[i]){
            long long ops = 1 + (long long)p*dp[i/p];

            if(minOps == -1 || ops<minOps){
                minOps = ops;
            }
        }
        dp[i] = minOps;
    }

    long long ans = 0;
    for(int i=0;i<n;i++){
        ans+=dp[a[i]];
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();

    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}