#include<bits/stdc++.h>

using namespace std;

void swapvalues(int arr1[],int arr2[],int ind1,int ind2){
    if(arr1[ind1]>arr2[ind2]) 
        swap(arr1[ind1],arr2[ind2]);
}

void merge_sortedarrays(int arr1[],int arr2[],int n,int m){
    int len=n+m;
    int gap=(len/2)+(len%2);
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            if(left<n && right>=n){
                swapvalues(arr1,arr2,left,right-n);
            }else if(left>=n){
                swapvalues(arr2,arr2,left-n,right-n);
            }else{
                swapvalues(arr1,arr1,left,right);
            }
            left++,right++;
        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
    
}

int main(){
    int arr1[]={1,3,5,7};
    int arr2[]={0,2,6,8,9};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    for(int i=0;i<n;i++) cout<<arr2[i]<<" ";
    cout<<endl;
    merge_sortedarrays(arr1,arr2,n,m);
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    for(int i=0;i<n;i++) cout<<arr2[i]<<" ";

    return 0;
}