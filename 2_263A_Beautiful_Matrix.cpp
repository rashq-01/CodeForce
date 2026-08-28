#include<bits/stdc++.h>

using namespace std;

int main(){
    int row = 0;
    int col = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int temp;
            cin>>temp;
            if(temp==1){
                row = i;
                col = j;
            }
        }
    }
    cout<<abs(row-2)+abs(col-2);

    return 0;
}