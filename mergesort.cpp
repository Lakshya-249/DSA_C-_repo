#include<bits/stdc++.h>
#include<vector>
using namespace std;

void merge(vector<int>&vec,int low,int mid,int high){
    vector<int>temp;

    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high){
        if(vec[left]<=vec[right]){
            temp.push_back(vec[left]);
            left++;
        }else{
            temp.push_back(vec[right]);
            right++;
        }
    }

    while (left<=mid){
        temp.push_back(vec[left]);
        left++;
    }
    while (right<=high){
        temp.push_back(vec[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        vec[i]= temp[i-low];
    }
    
}

void ms(vector<int>&vec,int low,int high){
    if(low==high) return;
    int mid=(low+high)/2;
    ms(vec,low,mid);
    ms(vec,mid+1,high);
    merge(vec,low,mid,high);
}

void mergesort(vector<int>&vec,int n){
    ms(vec,0,n-1);
}

int main(){
    vector<int>vec={3,2,1,6,1,6,7,4};
    for(auto it: vec) cout<<it<<" ";
    cout<<endl;
    int n=5;
    mergesort(vec,n);
    for(auto it:vec) cout<<it<<" ";
    return 0;
}