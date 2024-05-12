#include<bits/stdc++.h>
using namespace std;

void recur(int a,string chr){
    if(a>0){
        cout<<chr<<endl;
        a--;
        recur(a,chr);
    }else{
        cout<<"";
    }
}

int main(){
    recur(7,"Lakshya");
    return 0;
}