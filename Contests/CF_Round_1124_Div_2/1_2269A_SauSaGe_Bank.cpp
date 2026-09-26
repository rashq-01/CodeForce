#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n,k;
    cin>>n>>k;

    if(n==k){
        cout<<1LL*2*k<<endl;
        return;
    }

    int p = n - k + 1;
    cout<<(long long)pow(1LL*2 , p)+(2*(k-1))<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}



//475