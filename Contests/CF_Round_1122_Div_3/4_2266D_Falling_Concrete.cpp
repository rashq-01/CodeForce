#include<bits/stdc++.h>

using namespace std;

void solve(){
    int balllast = 0;
    int n;
    cin>>n;

    vector<long long> c(n);

    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        c[i] = a - (i+1);
    }
    sort(c.begin() , c.end());
    c.erase(unique(c.begin() , c.end()) , c.end());

    int maxLen = 1;
    int currLen = 1;

    for(size_t i = 1;i<c.size();i++){
        if(c[i] == c[i-1]+1){
            currLen++;
        }
        else{
            maxLen = max(maxLen , currLen);
            currLen = 1;
        }
    }
    maxLen = max(maxLen,currLen);
    cout<<maxLen<<endl;
}

int main(){
    int T;
    cin>>T;

    while(T--){
        solve();
    }

    return 0;
}