#include<bits/stdc++.h>

using namespace std;


int main(){
    int n,k;
    cin>>n>>k;

    int m = (n*2)+1;

    vector<int> arr(m);
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }

    while(k>0){
      for(int i=1;i<m && k>0;i++){
        if(i+1<m && arr[i]-1>arr[i-1] && arr[i]-1>arr[i+1]){
            arr[i]--;
            k--;
        }
      }  
    }
    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}