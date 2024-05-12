#include<bits/stdc++.h>

using namespace std;

int best_stock_day(int arr[],int n){
    int mini=0;
    int maxi=0;
    int diff=0;
    for(int i=1;i<n;i++){
        if(diff<(arr[i]-arr[mini])){
                diff=arr[i]-arr[mini];
                maxi=i;
        }else if(arr[mini]>arr[i])mini=i;
    }
    return diff;
}

int main(){
    int arr[]={7,4,5,3,6,4,8,1};
    int n=sizeof(arr)/sizeof(int);
    int ans=best_stock_day(arr,n);

    cout<<"Maximum profit: "<<ans;

    return 0;
}