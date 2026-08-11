#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0'){
                str[i] = '*';
                break;
            }
        }
        for(int i=0;i<str.size();i++){
            if(str[i] == '1'){
                str[i] = '*';
                break;
            }
        }
        string ans;
        for(int i=0;i<str.size();i++){
            if(str[i]=='1' || str[i] =='0')ans.push_back(str[i]);
        }
        cout<<ans<<endl;
    }
    return 0;

}