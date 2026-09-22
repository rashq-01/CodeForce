#include<bits/stdc++.h>

using namespace std;

void fun(){
    string s;
    cin>>s;

    string org = s;
    sort(s.begin() ,s.end());

    int low = 0;
    int high = 0;
    while(high<s.size() && low<s.size()){
        while(high<s.size() && s[low] != org[high]){
            high++;
        }
        if(high<s.size() && s[low] == org[high]){
            high++;
            low++;
        }
    }
    while(low<s.size()){
        s[low] = min((s[low]+1) , '9' + 0);
        low++;

    }
    cout<<s<<endl;

}

int main(){
    int T;
    cin>>T;
    while(T--){
        fun();
    }

    return 0;
}