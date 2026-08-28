#include<bits/stdc++.h>


using namespace std;


void fun(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    int bad = 0;
    for(int i=0;i+1<n;i++){
        if(s[i]==s[i+1])bad++;
    }
    
    cout<<(bad+1)/2<<endl;

}


int main(){
    int T;
    cin>>T;
    while(T--){
        fun();
    }


    return 0;
}


