#include<bits/stdc++.h>

using namespace std;

int getSum(int x){
    int sum = 0;
    while(x){
        int dig = x % 10;
        sum += (dig * dig);

        x/=10;
    }
    return sum;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int DAYS = 200;
    vector<vector<int>> history(n , vector<int>(200));
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        history[i][0] = a[i];

        for(int t=1;t<DAYS;t++){
            history[i][t] = getSum(history[i][t-1]);
        }

    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            bool inTune = false;

            for(int t=0;t<DAYS;t++){
                if(history[i][t] == history[j][t]){
                    inTune = true;
                    break;
                }
            }

            if(inTune)ans++;
        }
    }

    cout<<ans<<endl;
}



int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}


//863