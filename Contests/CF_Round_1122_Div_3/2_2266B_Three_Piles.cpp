#include<bits/stdc++.h>

using namespace std;

void fun(){
    long long a,b,c;
    cin>>a>>b>>c;

    long long ans = max(abs(a+c-b),abs(a-b));

    cout<<ans<<endl;
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