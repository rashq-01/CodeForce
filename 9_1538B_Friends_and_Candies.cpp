#include<bits/stdc++.h>

using namespace std;


void fun(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end(),greater<int>());

        int low = arr[0];
        int high = arr[0];
        for(auto& num : arr){
            if(num>high)high = num;
            if(num<low)low = num;
        }

        int sum = accumulate(arr.begin(),arr.end(),0);

        if(sum%n != 0){
            cout<<-1<<endl;
            continue;
        }
        int avg = sum/n;
        int extra = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(arr[i]<=avg){
                break;
            }

            extra += (arr[i] - avg);
            ans++;
        }
        cout<<ans<<endl;


        
    }
}

int main(){
    fun();

    return 0;
}