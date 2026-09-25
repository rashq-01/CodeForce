#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    map<int,int> freq;

    for(int i=0;i<n;i++){
        cin>>a[i];
        freq[a[i]]++;
    }

    vector<int> result;

    while(!freq.empty()){
        int M = freq.rbegin()->first;
        int c = freq[M];

        for(int i=0;i<c;i++){
            result.push_back(M);
        }
        freq.erase(M);
        

        vector<int> to_erase;
        for(auto& pair : freq){
            int val = pair.first;
            int take = min(pair.second , c);

            for(int i=0;i<take;i++){
                result.push_back(val);
            }
            pair.second -= take;

            if(pair.second == 0){
                to_erase.push_back(val);
            }
        }

        for(int val : to_erase){
            freq.erase(val);
        }
    }


    for(int i=0;i<n;i++){
        cout<<result[i]<<(i+1 == n ? "" : " ");
    }
    cout<<"\n";


}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}