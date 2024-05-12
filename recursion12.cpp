#include<bits/stdc++.h>
#include<vector>
using namespace std;

class solution {
    public:
        void recur(int arr[],vector<int>&st,int i,int n,int sum){
            if(i==n){
                st.push_back(sum);
                return;
            }
            sum+=arr[i];
            recur(arr,st,i+1,n,sum);
            sum-=arr[i];
            recur(arr,st,i+1,n,sum);
        }

        vector<int> recur_(int arr[],int n){
            vector<int>vec;
            recur(arr,vec,0,n,0);
            sort(vec.begin(),vec.end());
            return vec;
        }
};

int main(){
    solution s1;
    int arr[]={1,2,3};
    int n=(sizeof(arr)/sizeof(int));
    vector<int>vec1;
    vec1=s1.recur_(arr,n);
    for(auto it:vec1) cout<<it<<" ";
}