#include<bits/stdc++.h>
using namespace std;

void recur(int a,int b){
    /*if(a<=b){
        cout<<a<<endl;
        a++;
        recur(a,b);
    }else{
        cout<<"";
    }*/
    if(b>=a){
        cout<<b<<endl;
        b--;
        recur(a,b);
    }else{
        cout<<"";
    }
}

int main(){
    recur(3,6);
}