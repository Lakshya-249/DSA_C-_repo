#include <bits/stdc++.h>
using namespace std;
 
bool recur(int a,string &str){
    if(a>str.length()/2) return true;
    if(str[a]!=str[str.length()-a-1]) return false;
    recur(a+1,str);
}

int main(){
    string nstr;
    cout<<"Enter a word : ";
    cin>>nstr;
    cout<<"the entered word is a pallandrome(0/1) : "<<recur(0,nstr);
}