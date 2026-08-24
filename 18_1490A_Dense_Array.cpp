#include<bits/stdc++.h>

using namespace std;

void fun(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = 0;
    for(int i=0;i<n-1;i++){
        int big = max(arr[i],arr[i+1]);
        int small = min(arr[i],arr[i+1]);
        while(big > 2*small){
            big = (big+1)/2;
            ans++;
        }
        
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