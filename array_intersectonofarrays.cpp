#include<bits/stdc++.h>

using namespace std;

vector<int> intersect_array(vector<int>arr1,vector<int>arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    int i=0;
    int j=0;
    vector<int>ans;
    while (i<n1 && j<n2){
        if(arr1[i]<arr2[j])i++;
        else if(arr1[i]>arr2[j])j++;
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int>arr1,arr2;
    arr1={1,2,3,4,4,5};
    arr2={2,3,4,4,5,6};
    vector<int>ans=intersect_array(arr1,arr2);

    for(auto itr:ans) cout<<itr<<" ";

    return 0;
}