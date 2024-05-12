#include<bits/stdc++.h>

using namespace std;

int merge(int arr[],int low,int mid,int high){
    int cnt=0;
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while (right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]= temp[i-low];
    }

    return cnt;
}


int mergesort(int arr[],int low,int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low + high)/2;
    cnt += mergesort(arr,low,mid);
    cnt += mergesort(arr,mid+1,high);
    cnt += merge(arr,low,mid,high);
    return cnt;
}

int count_inversions(int arr[],int n){
    int ans=mergesort(arr,0,n-1);
    return ans;
}

int main(){
    int arr[]={5,3,2,1,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=count_inversions(arr,n);
    cout<<"Total number of inversion pairs in the give array: "<<ans;

    return 0;
}