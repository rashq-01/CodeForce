#include<bits/stdc++.h>


using namespace std;


void fun(){
        int n,m;
        cin>>n>>m;

        vector<string> words(n);
        vector<string> AB(m);

        for(int i=0;i<n;i++){
            cin>>words[i];
        }
        
        for(int i=0;i<m;i++){
            cin>>AB[i];
        }

        vector<bool> wordsMap(26,false);

        for(int i=0;i<n;i++){
            wordsMap[words[i][0]-'a'] = true;
        }

        for(int i=0;i<m;i++){
            for(auto& ch : AB[i]){
                if(!wordsMap[ch-'A']){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }

        cout<<"YES"<<endl;

}


int main(){
    int T;
    cin>>T;
    while(T--){
        fun();
    }

    return 0;
}