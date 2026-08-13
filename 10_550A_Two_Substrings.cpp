#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int idx1 = -1;
    int idx2 = -1;
    for(int i=0;i+1<s.size();i++){
        if(s[i]=='A' && s[i+1]=='B'){
            idx1 = i;
            break;
        }
    }
    for(int i=s.size()-1;i-1>=0;i--){
        if(s[i]=='A' && s[i-1]=='B'){
            idx2 = i-1;
            break;
        }
    }
    if(idx1==-1 || idx2==-1){
        cout<<"NO"<<endl;
        return 0;
    }

    if(idx1 != idx2+1 && idx1+1 !=idx2){
        cout<<"YES"<<endl;
        return 0;
    }
    idx1 = 0;
    idx2 = 0;
    for(int i=s.size()-1;i-1>=0;i--){
        if(s[i]=='B' && s[i-1]=='A'){
            idx1 = i-1;
            break;
        }
    }
    for(int i=0;i+1<s.size();i++){
        if(s[i]=='B' && s[i+1]=='A'){
            idx2 = i;
            break;
        }
    }
    if(idx1==-1 || idx2==-1){
        cout<<"NO"<<endl;
        return 0;
    }

    if(idx1 != idx2+1 && idx1+1 !=idx2){
        cout<<"YES"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;



    return 0;
}