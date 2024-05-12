#include<bits/stdc++.h>
using namespace std;

void recur(int n){
    if(n>0){
        //cout<<n<<endl;
        n--;
        recur(n);
        cout<<n+1<<endl;
    }else{
        cout<<0<<endl;
    }
}

int main(){
    recur(9);
    return 0;
}