#include<bits/stdc++.h>

using namespace std;

vector<int> mergesorted_array(vector<int>arr1,vector<int>arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    vector<int>ans;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(ans.size()==0 || ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
        }else{
            if(ans.size()==0 || ans.back()!=arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(ans.size()==0 || ans.back()!=arr1[i]){
            ans.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n2){
        if(ans.size()==0 || ans.back()!=arr2[j]){
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}

int main(){
    vector<int>arr1,arr2;
    arr1={1,1,3,4,4,5};
    arr2={2,3,3,4,5,6};
    vector<int>ans=mergesorted_array(arr1,arr2);

    for(auto itr:ans)cout<<itr<<" ";

    return 0;
}