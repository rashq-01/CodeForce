#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    
    while(T--){
        int n,k;
        cin>>n>>k;

        long long right = LLONG_MAX;
        long long left = 1;
        long long ans = 0;
        long long mid = 0;
        while(left<right){
            mid = left - (left-right)/2;
            if((mid/n)*(n-1) >= k){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        mid = right;
        ans = ((mid/n)*n) - (((mid/n)*(n-1)-k))-1;
        cout<<ans<<endl;


    }


    return 0;
}