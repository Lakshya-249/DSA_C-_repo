#include<bits/stdc++.h>

using namespace std;

vector<int> majority_elem(vector<int>vec){
    int n=vec.size();
    int cnt1=0,cnt2=0;
    int elem1,elem2;
    for(int i=0;i<n;i++){
        if(cnt1==0 && vec[i]!=elem2){
            cnt1=1;
            elem1=vec[i];
        }else if(cnt2==0 && vec[i]!=elem1){
            cnt2=1;
            elem2=vec[i];
        }else if(vec[i]==elem1) cnt1++;
        else if(vec[i]==elem2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++){
        if(vec[i]==elem1)cnt1++;
        if(vec[i]==elem2) cnt2++;
    }
    vector<int>ans;
    int mini= (int)(n/3)+1;
    if(cnt1>=mini) ans.push_back(elem1);
    if(cnt2>=mini) ans.push_back(elem2);

    return ans;
}

int main(){
    vector<int>arr={1,1,1,3,3,2,2,2};
    vector<int>ans=majority_elem(arr);
    cout<<"Majority elements are: ";
    for(auto it: ans) cout<<it<<" ";

    return 0;
}