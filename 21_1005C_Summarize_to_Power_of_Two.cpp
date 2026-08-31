#include<bits/stdc++.h>


using namespace std;
bool isValid(int n){
    int count = 0;
    while(n){
        int bit = n&1;
        count+=bit;
        if(count>1)return false;
        n>>=1;
    }

    return true;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,bool>> arr(n,{0,false});
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
    }

    for(int i=0;i<n;i++){
        if(arr[i].second)continue;

        for(int j=0;j<n;j++){
            if(i==j)continue;

            int sum = arr[i].first + arr[j].first;

            if(isValid(sum)){
                arr[i].second = true;
                arr[j].second = true;
                break;
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        if(!arr[i].second)ans++;
    }

    cout<<ans;

    return 0;
}