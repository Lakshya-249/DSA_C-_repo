#include<bits/stdc++.h>

using namespace std;

int largestkth_subarray_sum(vector<int>arr,int k){
    vector<int>ans;
    int size=arr.size();
    for(int i=0;i<size;i++){
        int sum=0;
        for(int j=i;j<size;j++){
            sum+=arr[j];
        }
        ans.push_back(sum);
    }
    sort(ans.begin(),ans.end());
    return ans[ans.size()-k];
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    int largestkthsum=largestkth_subarray_sum(arr,3);
    cout<<"Answer of kth largest sum: "<<largestkthsum;

    return 0;
}