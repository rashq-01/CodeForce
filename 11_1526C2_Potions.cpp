#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];

    priority_queue<int,vector<int>,greater<int>> minHeap;

    long long prefixSum = 0;
    for(auto& x : arr){
        prefixSum+=x;
        minHeap.push(x);

        if(prefixSum<0){
            int smallest = minHeap.top();
            minHeap.pop();

            prefixSum -= smallest;
        }
    }
    cout<<minHeap.size()<<endl;
    return 0;
}