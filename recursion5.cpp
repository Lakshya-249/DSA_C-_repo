#include<bits/stdc++.h>
using namespace std;

void recur(int i,int arr[],int n){
    if(i>=n/2) return;
    int ln=arr[i];
    arr[i]=arr[n-i-1];
    arr[n-i-1]=ln;
    recur(i+1,arr,n);
}


int main(){
    int a;
    cout<<"enter length of your array : ";
    cin>>a;
    int arr[a];
    for (int i=0;i<a;i++) cin>>arr[i];
    recur(0,arr,a);
    for (auto i:arr) cout<<i<<endl;
} 