#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main(){
    int arr[]={10,20,30,40,60,80};
    int len= sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<(1<<len);i++){
        int sum=0;
        vector<int>vec;
        for(int x=0;x<len;x++){
            if((i>>x)&1) sum+=arr[x];
            else sum-=arr[x];
            vec.push_back((i>>x)&1);
        }
        if(!sum){
            for(auto itr:vec) cout<<itr<<" ";
            break;
        }
    }
    return 0;
}