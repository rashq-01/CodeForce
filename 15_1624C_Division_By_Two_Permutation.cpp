#include<bits/stdc++.h>

using namespace std;
void fun(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> freq(n+1,0);

    for(auto num : arr){
        while(num>n)num/=2;
        freq[num]++;

    }
    for(int i=n;i>1;i--){
        if(freq[i] > 1){
            freq[i/2] += (freq[i]-1);
            freq[i] = 1;
        }
    }

    for(int i=1;i<=n;i++){

        if(freq[i]==0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        fun();
    }
}