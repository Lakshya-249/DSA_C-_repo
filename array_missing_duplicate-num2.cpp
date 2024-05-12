#include<bits/stdc++.h>

using namespace std;

vector<int> find_missing_duplicate(vector<int>arr){
    int n=arr.size();
    int xr=0;
    for(int i=0;i<n;i++){
        xr=xr^arr[i];
        xr=xr^(i+1);
    }
    int bitn=0;
    while(1){
        if(xr & (1<<bitn)) break;
        bitn++;
    }
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++){
        if(arr[i] & (1<<bitn)){
            one=one^arr[i];
            one=one^(i+1);
        }else{
            zero=zero^arr[i];
            zero=zero^(i+1);
        }
    }
    return {(int)zero,(int)one};
}

int main(){
    vector<int>arr={1,1,2,3,4,6};
    vector<int>ans=find_missing_duplicate(arr);
    cout<<"Missing  number: "<<ans[1]<<endl;
    cout<<"Duplicate number: "<<ans[0];

    return 0;
}