#include<bits/stdc++.h>

using namespace std;

  long long findMinimumSum(vector<int> power) {
    int pre = 0;
    int ans = 0;
    for(int i=1;i<power.size();i++){
      power[i] += pre;

      if(power[i]<power[i-1]){
        pre += (power[i-1] - power[i]);
        power[i] = power[i-1];
      }
      
    }

    return pre;
  }

int main(){
    vector<int> arr = {3,5,2,3};

    cout<<findMinimumSum(arr);

    return 0;
}