#include<bits/stdc++.h>

using namespace std;

void fun(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    int ans = INT_MAX;

    for(int i=0;i+1<n;i++){
        ans = min(ans,arr[i+1]-arr[i]);
    }

    cout<<ans<<endl;

}

int main(){
    int T;
    cin>>T;
    while(T--){
        fun();
    }
}