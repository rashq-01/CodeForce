#include<bits/stdc++.h>

using namespace std;


int main(){

    int T;
    cin>>T;
    
    while(T--){
        int n,m;
        cin>>n>>m;

        vector<vector<int>> arr(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }

        int ans = 0;

        int len = n + m -1;

        for(int d=0;d<len/2;d++){
            int cnt[2] = {0,0};

            for(int i=0;i<n;i++){
                int j = d - i;

                if(j>=0 && j<m){
                    cnt[arr[i][j]]++;
                }
            }

            int sum = (n-1) + (m-1) - d;

            for(int i=0;i<n;i++){
                int j = sum - i;

                if(j>=0 && j<m)cnt[arr[i][j]]++;
            }

            ans += min(cnt[0],cnt[1]);
        }

        cout<<ans<<endl;
    }
    return 0;
}