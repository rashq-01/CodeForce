#include<bits/stdc++.h>

using namespace std;


void solve(){
    int n;
    long long x;
    cin>>n>>x;

    vector<long long> primes;
    long long temp = x;

    for(long long i=2;i*i<=temp;i++){
        if(temp%i==0){
            primes.push_back(i);
            while(temp%i ==0){
                temp/=i;
            }
        }
    }

    if(temp>1)primes.push_back(temp);

    vector<long long> sums(primes.size() , 0);

    for(int i=0;i<n;i++){
        long long a;
        cin>>a;

        for(size_t j=0;j<primes.size();j++){
            if(a % primes[j] == 0){
                sums[j] += a;
            }
        }
    }

    long long maxSum = 0;
    for(long long s : sums){
        maxSum = max(maxSum , s);
    }

    cout<<maxSum<<endl;


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}