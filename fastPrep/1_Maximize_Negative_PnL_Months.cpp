#include<bits/stdc++.h>

using namespace std;


  int solve(int i,int prefixSum,vector<int>& arr){
    if(i>=arr.size())return 0;

    int maxLen = 0;
    if(prefixSum-arr[i]>0){
      maxLen = 1 + solve(i+1,prefixSum-arr[i],arr);
    }
    maxLen = max(maxLen,solve(i+1,prefixSum+arr[i],arr));


    return maxLen;
  }
  int maximizeNegativePnLMonths(vector<int> PnL) {
    int n = PnL.size();
    // int maxNum = solve(0,0,PnL);

    priority_queue<int> maxHeap;
    long long prefixSum = 0;

    for(auto& x : PnL){
        prefixSum -= x;
        maxHeap.push(x);

        while(prefixSum<=0){
            int large = maxHeap.top();
            maxHeap.pop();
            prefixSum += (2LL * large); // since it is already subtracted in prefixSum so for making it prefixSum including this number also in the sum we have to add two times
        }
    }

    return maxHeap.size();
  }



int main(){
    vector<int> arr = {5, 2, 3, 5, 2, 3};
    cout<<maximizeNegativePnLMonths(arr);

    return 0;
}