#include<bits/stdc++.h>

using namespace std;

void fun(){
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    int ans = 0;
    for(int idx=0;idx<n;idx+=k){
        int i = idx;
        bool isFound = false;
        while(i<idx+k){
            if(s[i]=='0'){
                isFound = true;
                break;
            }
            i++;
        }

        if(!isFound)ans++;
    }

    cout<<ans<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        fun();
    }

    return 0;
}