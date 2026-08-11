#include<bits/stdc++.h>

using namespace std;



int main(){
    int T;
    cin>>T;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;

        int count = 0;
        if(a!=b && b!=c && c!=a){
            if((a > b && a < c) || (a > c && a < b))
                count = min(abs(a-b), abs(a-c));

            else if ((b > a && b < c) || (b > c && b < a))
                count = min(abs(b-a), abs(b-c));

            else
                count = min(abs(c-a), abs(c-b));
        }
        cout<<count<<endl;
    }

    return 0;
}