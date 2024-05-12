#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main(){
    int arr[]={1,1,5,6,6,7,8,8,9,3,9,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    int xor1=0;
    for(int i=0;i<len;i++){
        xor1=xor1^arr[i];
    }
    int ind=0;
    while(true){
        if(xor1&(1<<ind)){
            break;
        }
        ind++;
    }
    
    int xor2=0,xor3=0;
    for(int x=0;x<len;x++){
        if(arr[x]&(1<<ind)){
            xor2=xor2^arr[x];
        }
        else{
            xor3=xor3^arr[x];
        }
    }
    cout<<"The answers are: "<<xor2<<" "<<xor3;
    return 0;
}