#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> find_3sum(vector<int>arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum>0){
                k--;
            }else if(sum<0){
                j++;
            }else{
                vector<int>temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(arr[j]==arr[j-1]) j++;
                while(arr[k]==arr[k+1]) k--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int>arr={-2,-2,-2,-1,-1,-1,2,0,0,0,2,2,2};
    // vector<int>arr={-1,0,1,2,-1,-4};
    vector<vector<int>>ans=find_3sum(arr);
    cout<<"Unique 3 elements which gives zeroes: "<<endl;
    for(auto it: ans){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }

    return 0;
}