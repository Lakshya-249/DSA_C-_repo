#include<bits/stdc++.h>

using namespace std;

int find_majority_elem(int arr[],int n){
    int num,j=0;
    for(int i=0;i<n;i++){
        if(j==0){
            num=arr[i];
            j++;
        }
        else if(arr[i]!=num)j--;
        else j++;
    }
    j=0;
    for(int i=0;i<n;i++){
        if(arr[i]==num)j++; 
    }
    if(j>(n/2)) return num;
    return -1;
}

int main(){
    int arr[]={7,7,5,7,5,7,7,7,5,3,7,7,5,3,7,5,3,3,7,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=find_majority_elem(arr,n);

    cout<<"Majority element isn the array: "<<ans<<"\t"<<n;
    return 0;
}