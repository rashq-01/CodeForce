#include<bits/stdc++.h>

using namespace std;

void fun(){
    int n;
    cin>>n;
    
    string s;
    cin>>s;


    if(s[0] == '1'){
        int cnt = 0;
        for(char c : s){
            if(c=='0')cnt++;
        }
        cout<<cnt<<endl;
        return;
    }

    int p = -1;

    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            p = i;
            break;
        }
    }
    if(p==-1){
        cout<<0<<endl;
        return;
    }

    vector<int> ones(n+1,0);
    for(int i=0;i<n;i++){
        ones[i+1] = ones[i] + (s[i] == '1' ? 1 : 0);
    }

    vector<int> zeros(n+1,0);
    for(int i=n-1;i>=0;i--){
        zeros[i] = zeros[i+1] + (s[i] == '0' ? 1 : 0);
    }

    int minOps = n;
    for(int c=p;c<=n;c++){
        int cost = ones[c] + zeros[c];
        minOps = min(minOps,cost);
    }

    cout<<minOps<<endl;



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        fun();
    }

    return 0;
}