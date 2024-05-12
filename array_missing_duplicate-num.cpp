#include<bits/stdc++.h>

using namespace std;

vector<int> find_missing_duplicate(vector<int>arr){
    int n=arr.size();
    int sn=(n*(n+1))/2;
    int s2n=(n*(n+1)*(2*n+1))/6;
    int s=0,s2=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        s2+=arr[i]*arr[i];
    }
    int val1=s-sn;
    int val2=s2-s2n;
    val2/=val1;
    int x=(val1+val2)/2;
    int y=val2-x;
    return {(int)x,(int)y};
}

int main(){
    vector<int>arr={1,1,2,3,4,6};
    vector<int>ans=find_missing_duplicate(arr);
    cout<<"Duplicate number: "<<ans[0]<<endl;
    cout<<"Missing  number: "<<ans[1];

    return 0;
}