#include<bits/stdc++.h>

using namespace std;

bool isValid(vector<int>& freq){
    return (freq[1]>0 && freq[2]>0 && freq[3]>0);
}

void fun(){
    string s;
    cin>>s;

    int n = s.size();
    vector<int> freq(4,0);

    int left = 0;
    int ans = INT_MAX;

    for(int right=0;right<n;right++){
        freq[s[right] - '0']++;

        while(isValid(freq)){
            ans = min(ans , right - left + 1);
            freq[s[left] - '0']--;
            left++;
        }
    }

    cout<<(ans==INT_MAX ? 0 : ans)<<endl;
}

int main(){
    
    int T;
    cin>>T;
    while(T--){
        fun();
    }

    return 0;
}