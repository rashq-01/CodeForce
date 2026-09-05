#include<bits/stdc++.h>

using namespace std;

void fun(){
    int n;
    cin>>n;
    int ones = 0;
    int oddOpZeros = 0;
    int evenOpZeros = 0;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num%2 == 1){
            ones++;
        }
        else{
            int op = num/2;

            if(op%2==1){
                oddOpZeros++;
            }
            else{
                evenOpZeros++;
            }
        }
    }

    cout<<max(ones,max(oddOpZeros,evenOpZeros))<<endl;
}


int main(){

    int T;
    cin>>T;
    while(T--){
        fun();
    }

    return 0;
}