#include<bits/stdc++.h>

using namespace std;


void fun(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> ans;
        int count = 0;
        int p = 0;
        while(n){
            int dig = n % 10;

            if(dig!=0){
                ans.push_back(dig * pow(10,p));
                count++;
            }
            n/=10;
            p++;
        }

        cout<<count<<endl;
        for(auto& num : ans)cout<<num<<" ";

        cout<<endl;
    }
}

int main(){
    fun();


    return 0;
}