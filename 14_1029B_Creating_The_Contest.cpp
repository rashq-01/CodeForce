#include<bits/stdc++.h>

using namespace std;





int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);

    for(int i=0;i<n;i++) cin>>arr[i];

    int ans = 1;
    int i = 0;
    int j = 0;
    while(j<n){
        while(j+1 < n && arr[j+1]<=arr[j]*2)j++;
        ans = max(ans,j-i+1);
        i=j+1;
        j++;
    }



    cout<<ans<<endl;



    return 0;
}