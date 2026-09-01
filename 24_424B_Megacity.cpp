#include<bits/stdc++.h>


using namespace std;


int main(){
    int n,currPopulation;
    cin>>n>>currPopulation;

    vector<pair<long long,long long>> cities;;

    for(int i=0;i<n;i++){
        int row,col;
        long long val;
        cin>>row>>col>>val;
        long long distSqr = row*row + col*col;
        cities.push_back({distSqr,val});
    }

    sort(cities.begin(),cities.end());

    for(auto& city : cities){
        currPopulation += city.second;

        if(currPopulation>=1000000){
            cout << fixed << setprecision(7) << sqrt((double)city.first) << endl;
            return 0;
        }
    }

    cout<<-1<<endl;
   

    return 0;
}