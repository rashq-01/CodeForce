#include<bits/stdc++.h>

using namespace std;

void fun(){
    int n,m;
    cin>>n>>m;

    vector<int> Bea(n);
    vector<int> Ver(m);
    for(int i=0;i<n;i++){
        cin>>Bea[i];
    }
    for(int i=0;i<m;i++){
        cin>>Ver[i];
    }

    int isBeaTurn = true;

    int beaIdx = 0;
    int verIdx = 0;
    while(true){
        if(beaIdx + 1 < n && (Bea[beaIdx] + 1 == Bea[beaIdx+1])){
            beaIdx++;
        }
        if(verIdx+1<m && (Ver[verIdx]+1 == Ver[verIdx+1])){
            verIdx++;
        }


        if(Bea[beaIdx]==0 && Ver[verIdx]==0){
            cout<<1<<endl;
            return;
        }
        if(Bea[beaIdx]==0){
            cout<<2<<endl;
            return;
        }

        if(Ver[verIdx]==0){
            cout<<1<<endl;
            return;
        }

        int targetBea = (beaIdx + 1 <n) ? (Bea[beaIdx + 1]-1) : 0;
        int targetVer = (verIdx+1<m) ? (Ver[verIdx+1]-1) : 0;

        int dropsBea = Bea[beaIdx] - targetBea;
        int dropsVer = Ver[verIdx] - targetVer;

        int diff = min(dropsBea,dropsVer);

        Bea[beaIdx] -= diff;
        Ver[verIdx] -= diff;
    }

}
int main(){
    int T;
    cin>>T;

    while(T--){
        fun();
    }


    return 0;
}