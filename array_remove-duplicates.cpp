#include<bits/stdc++.h>

using namespace std;

void remove_duplicates(int arr[],int &n){
    int i=0,j=0;
    while(j<n){
        if(arr[i]==arr[j]){
            j++;
        }else{
            arr[i+1]=arr[j];
            i++;
            j++;
        }
    }
    n=i+1;
}

int main(){
    int arr[]={1,1,2,2,2,3,3,3,4,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int index;
    remove_duplicates(arr,n);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";

    return 0;
}