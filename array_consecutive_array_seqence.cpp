#include<bits/stdc++.h>

using namespace std;

int longest_consec_seq(int arr[],int n){
    if(n==0){
        return 0;
    }
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int longest=1;
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                cnt++;
                x++;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
}

int main(){
    int arr[]={101,103,1,1,4,101,102,104,103,3,3,3,2,2,4,1,5,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int length=longest_consec_seq(arr,n);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl<<n;
    cout<<endl;
    cout<<"The length of the biggest consecutive sequence is: "<<length;

    return 0;
}