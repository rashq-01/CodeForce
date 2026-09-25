#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    char ch;
    cin>>n;
    cin>>ch;

    string s;
    cin>>s;

    int low = 0;
    int high = s.size()-1;
    
    int ans = 0;

    while(low<high){
        if(s[low] != s[high]){
            if(s[low] != ch)ans++;
            if(s[high] != ch)ans++;
        }

        low++;
        high--;
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