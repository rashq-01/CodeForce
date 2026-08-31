#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    long long first = 0;
    long long last = 0;

    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        if(i==0){
            first = x;
        }
        if(i==n-1)last = x;
    }
    cout<<gcd(first,last)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}