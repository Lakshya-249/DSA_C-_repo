#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[]{1,4,3,18,2,5,7,24,9,14,12};
    sort(arr,arr+11);
    for(int i=0 ;i<11;i++)cout<<arr[i]<<" ";
    cout<<endl;
    int high=10;
    int low=0;
    while (true){
        int mid=(high+low)/2;
        if(arr[mid]==14){
            cout<<mid;
            break;
        }else if(arr[mid]<14){
            low=mid;
        }else high=mid;
    }
    return 0;
}