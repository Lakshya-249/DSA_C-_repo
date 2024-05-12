#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> find_4sum(vector<int>arr){
    int n=arr.size();
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1])continue;
            int k=j+1;
            int z=n-1;
            while(k<z){
                long long sum=arr[i]+arr[j];
                sum+=arr[k];
                sum+=arr[z];
                if(sum<0) k++;
                else if(sum>0) z--;
                else{
                    vector<int>temp={arr[i],arr[j],arr[k],arr[z]};
                    k++;
                    z--;
                    while(arr[k]==arr[k-1]) k++;
                    while(arr[z]==arr[z+1]) z--;
                    ans.push_back(temp);
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int>arr={1,0,-1,-2,2,0};
    vector<vector<int>>ans=find_4sum(arr);
    for(auto it: ans){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }

    return 0;
}
