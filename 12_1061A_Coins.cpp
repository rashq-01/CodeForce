#include<bits/stdc++.h>

using namespace std;

// int solve(int n,int s,vector<int>& dp){
//     if(s<0)return INT_MAX;

//     if(s==0){
//         return 0;
//     }
//     if(dp[s] != -1)return dp[s];

//     int minNum = INT_MAX;
//     for(int i=1;i<=n;i++){
//         int res = solve(n,s-i,dp);
//         if(res!=INT_MAX){
//             minNum = min(minNum,res + 1);
//         }
//     }

//     dp[s] = minNum;
//     return dp[s];
// }
int main(){
    int n;
    int s;
    cin>>n>>s;
    // vector<int> dp(s+1,-1);

    // cout<<solve(n,s,dp)<<endl;

    int ans = 0;
    while(s>0){
        int coin = min(s,n);
        ans++;
        s-=coin;
    }

    cout<<ans<<endl;

    return 0;
}