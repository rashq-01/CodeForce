#include<bits/stdc++.h>

using namespace std;


void fun(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    sort(arr.begin(),arr.end());

    long long rem = 0;
    int count = 0;
    for(int i=n-1;i>=0;i--){
        long long curr = rem + arr[i];
        if(curr<k)break;
        rem = curr - k;
        count++;
    }

    cout<<count<<endl;
}

int main(){

    int T;
    cin>>T;
    while(T--){
        fun();
    }

    return 0;
}