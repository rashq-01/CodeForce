#include<bits/stdc++.h>

using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){
        vector<int> arr(3,0);
        cin>>arr[0]>>arr[1]>>arr[2];

        sort(arr.begin(),arr.end());

        while(arr[2] > (arr[0] + arr[1])){
            arr[2] = arr[1] + arr[0];
            sort(arr.begin(),arr.end());
        }

        cout<<arr[2] - arr[0]<<endl;




    }

    return 0;
}