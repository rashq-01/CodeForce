#include<bits/stdc++.h>

using namespace std;

void fun(){
    string str;
    cin>>str;

    int h = stoi(str.substr(0,2));
    int m = stoi(str.substr(3,2));

    int start = h*60 + m;

    for(int ans=0;ans<1440;ans++){
        int curr = (start + ans) % 1440;

        int hh = curr / 60;
        int mm = curr % 60;

        if(hh%10 == mm/10 && mm%10==hh/10){
            cout<<ans<<endl;
            return;
        }
    }
}

int main(){
    fun();
    return 0;
}