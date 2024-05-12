#include<bits/stdc++.h>

using namespace std;

void move_0stoend(int arr[],int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

int main(){
    int arr[]={1,0,2,3,1,0,4,0,0,5,3,0,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    move_0stoend(arr,n);

    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    return 0;
}