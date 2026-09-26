#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<long long> a(n);
    long long totalSum = 0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        totalSum += a[i];
    }

    if(k==1){
        cout<<totalSum<<endl;
        return;
    }

    long long keepSum = 0;

    int P = min(k-1,n-k+1);

    for(int i=0;i<P;i++){
        keepSum += min(a[i] , a[n-1-i]);
    }

    if(n < 2 * k -1){
        int overlapStart = n - k + 1;
        int overlapEnd = k - 2;

        for(int i=overlapStart;i<=overlapEnd;i++){
            keepSum+=a[i];
        }
    }

    cout<<totalSum-keepSum<<endl;

}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}


//992