#include<bits/stdc++.h>

using namespace std;

void fun(){
    int n;
    cin>>n;

    int a,b,c;
    cin>>a>>b>>c;

    cout<<n-min(a,min(b,c))<<endl;
}

int main(){
    int T;
    cin>>T;

    while(T--){
        fun();
    }

    return 0;
}