#include<bits/stdc++.h>

using namespace std;


int main(){

    int count = 0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        if(temp[1]=='+')
            count++;
        else
            count--;
    }

    cout<<count;

    return 0;
}