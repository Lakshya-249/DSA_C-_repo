#include<bits/stdc++.h>

using namespace std;

void next_permutation(vector<int>&arr){
    int n=arr.size();
    int ind=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1){
        reverse(arr.begin(),arr.end());
        return;
    }
    for(int i=n-1;i>ind;i--){
        if(arr[i]>arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr.begin()+ind+1,arr.end());
    return;
}

int main(){
    vector<int>arr={2,1,5,4,3,0,0};
    for(auto it:arr) cout<<it<<" ";
    cout<<endl;
    next_permutation(arr);
    for(auto it:arr) cout<<it<<" ";
    cout<<endl;
    next_permutation(arr);
    for(auto it:arr) cout<<it<<" ";

    return 0;
}