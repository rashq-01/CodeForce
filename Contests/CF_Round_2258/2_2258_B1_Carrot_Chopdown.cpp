#include<bits/stdc++.h>

using namespace std;


void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> freq(m+1,0);

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        freq[x]++;
    }


    vector<int> greater(m+2,0);
    int suffix = 0;
    for(int y=m;y>=1;y--){
        greater[y] = suffix;
        suffix += freq[y];
    }

    int ans = 0;
    for(int y=1;y<=m;y++){
        int curr = freq[y] + greater[y];

        if(2*y <= m){
            curr+=freq[2*y];
        }
        ans = max(ans,curr);
    }

    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;

    while(T--){
        solve();
    }


    return 0;
}