#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> t(n);

    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>t[i];

    vector<long long> prefixZero(n,0);
    
    long long totalZeroSum = 0;
    long long totalOneSum = 0;
    for(int i=0;i<n;i++){
        if(t[i]==1)totalOneSum+=a[i];

        if(t[i]==0)totalZeroSum += a[i];
        prefixZero[i] = totalZeroSum;
    }

    long long ans = -1;


    for(int i=0;i<n;i++){

        long long prevZeroSum = i-1 >=0 ? prefixZero[i-1] : 0;
        long long nextZeroSum = i+k-1 < n ? prefixZero[i+k-1] : totalZeroSum;


        long long currBest = totalOneSum + (nextZeroSum - prevZeroSum);
        ans = max(ans,currBest);

    }
    cout<<ans;


    return 0;
}