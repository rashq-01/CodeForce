#include<bits/stdc++.h>

using namespace std;

void toLower(string& str){
    for(auto& ch : str){
        if(ch>=65 && ch<=90){
            ch = ch+32;
        }
    }
}

int main(){
    int n;
    cin>>n;
    cin.ignore();

    unordered_map<string,int> mp;

    for(int i=0;i<n;i++){
        string str;
        getline(cin,str);

        string name1,name2;
        int idx = 0;
        while(idx<str.size() && str[idx] != ' ')name1.push_back(str[idx++]);
        idx = str.size()-1;
        while(idx>=0 && str[idx] != ' ')name2.push_back(str[idx--]);
        reverse(name2.begin(),name2.end());
        toLower(name1);
        toLower(name2);

        if(!mp.count(name2)){
            mp[name2] = 1;
        }

        if(!mp.count(name1)){
            mp[name1] = 1 + mp[name2];
        }
        else{
            mp[name1] = max(mp[name1] , 1 + mp[name1]);
        }
    }
    int ans = 0;
    for(auto& [name , len] : mp){
        ans = max(ans,len);
    }
    cout<<ans;


    

    // for(auto& el : adj){
    //     int id = el.second.first;
    //     string name1 = el.first;
    //     vector<string> shared = el.second.second;
    //     if(shared.size()==0)continue;

    //     cout<<"ID : "<<id<<" Name : "<<name1<<" Shared : ";
    //     for(auto name2 : shared)cout<<name2<<" ";

    //     cout<<endl;
    // }

    return 0;
}