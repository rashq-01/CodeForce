#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main(){
    int n;
    cin>>n;
    vector<string> arr(n,"");
    for(int i=0;i<n;i++)cin>>arr[i];

    for(int i=0;i<n;i++){
        string str = arr[i];

        if(str.size()>10){
            arr[i] = str[0] + to_string(str.size()-2) + str.back();
        }
        cout<<arr[i]<<endl;
    }

    return 0;
}