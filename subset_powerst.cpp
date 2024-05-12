#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int len=sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>>vect;
    for(int i=0;i<(1<<len);i++){
        vector<int>vec={};
        for(int bit=0;bit<len;bit++){
            if(i&(1<<bit)){
                vec.push_back(arr[bit]);
            }
        }
        vect.push_back(vec);
    }
    for(auto it1:vect){
        for(auto it2: it1){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
    return 0;
}