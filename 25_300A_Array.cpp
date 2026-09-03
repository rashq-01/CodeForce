#include<bits/stdc++.h>

using namespace std;


int main(){

    int n;
    cin>>n;

    vector<int> less;
    vector<int> greater;
    vector<int> zero;

    for(int i=0;i<n;i++){
        int curr;
        cin>>curr;
        
        if(curr<0){
            less.push_back(curr);
        }
        else if(curr>0){
            greater.push_back(curr);
        }
        else{
            zero.push_back(curr);
        }
    }

    if(greater.size()>0){
        if(less.size()%2 == 0){
            zero.push_back(less.back());
            less.pop_back();
        }

        cout<<less.size();
        for(auto& num : less)cout<<" "<<num;

        cout<<endl;

        cout<<greater.size();
        for(auto& num : greater)cout<<" "<<num;

        cout<<endl;

        cout<<zero.size();
        for(auto& num : zero)cout<<" "<<num;

        cout<<endl;

        return 0;
    }

    greater.push_back(less.back());
    less.pop_back();
    greater.push_back(less.back());
    less.pop_back();

    if(less.size()%2 == 0){
        zero.push_back(less.back());
        less.pop_back();
    }

    cout<<less.size();
    for(auto& num : less)cout<<" "<<num;

    cout<<endl;

    cout<<greater.size();
    for(auto& num : greater)cout<<" "<<num;

    cout<<endl;

    cout<<zero.size();
    for(auto& num : zero)cout<<" "<<num;

    cout<<endl;


    return 0;
}