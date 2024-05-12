#include<bits/stdc++.h>
using namespace std;

int recur(int num){
    if(num<=1){
        return num;
    }
    int sclast=recur(num-2);
    int last=recur(num-1);
    return last+sclast; 
}

int main(){
    int c;
    cout<<"enter number : ";
    cin>>c;
    cout<<recur(c);
    return 0;
}