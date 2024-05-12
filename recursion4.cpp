#include<bits/stdc++.h>
using namespace std;

int recur(int a){
    if(a>0){
        return a + recur(a-1);
    }else {
        return 0;
    }
}

int main(){
    int a;
    cout<<"Enter number : ";
    cin>>a;
    cout<<recur(a)<<endl;
}