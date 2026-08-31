#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];

    int totalProb = 0;
    sort(arr.begin(),arr.end());
    for(int i=0;i+1<n;i+=2){
        totalProb += (arr[i+1]-arr[i]);
    }

    cout<<totalProb;


    return 0;
}