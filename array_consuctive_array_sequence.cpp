#include<bits/stdc++.h>

using namespace std;

int longest_consec_seq(int arr[],int n){
    if(n==0){
        return 0;
    }
    sort(arr,arr+n);
    int longest=1;
    int elem=INT_MIN;
    int cnt=0;
    for(int i=0;i<n;i++){
        if((arr[i]-1)==elem){
            cnt=cnt+1;
            elem=arr[i];
        }else if(arr[i]!=elem){
            cnt=1;
            elem=arr[i];
        }
        longest=max(longest,cnt);
    }
    return longest;
}

int main(){
    int arr[]={101,103,1,1,4,101,102,104,103,3,3,3,2,2,4,1,5,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int length=longest_consec_seq(arr,n);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl<<n;
    cout<<endl;
    cout<<"The length of the biggest consecutive sequence is: "<<length;

    return 0;
}