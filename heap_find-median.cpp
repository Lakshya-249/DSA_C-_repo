#include<bits/stdc++.h>

using namespace std;

int signum(int a,int b){
    if(a==b) return 0;
    else if(a>b) return 1;
    else return -1;
}

void callmedian(int element,priority_queue<int>&maxh,priority_queue<int,vector<int>,greater<int>>&minh,int &median){
    switch (signum(maxh.size(),minh.size()))
    {
    case 0:
        if(element>median){
            minh.push(element);
            median=minh.top();
        }else{
            maxh.push(element);
            median=maxh.top();
        }
        break;
    case 1:
        if(element>median){
            minh.push(element);
            median=(minh.top()+maxh.top())/2;
        }else{
            minh.push(maxh.top());
            maxh.pop();
            maxh.push(element);
            median=(maxh.top()+minh.top())/2;
        }
        break;
    case -1:
        if(element>median){
            maxh.push(minh.top());
            minh.pop();
            minh.push(element);
            median=(maxh.top()+minh.top())/2;
        }else{
            maxh.push(element);
            median=(minh.top()+maxh.top())/2;
        }
    default:
        break;
    }
}

vector<int> findmedian(vector<int>arr,int n){
    vector<int>ans;
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    int median=0;
    for(int i=0;i<n;i++){
        callmedian(arr[i],maxh,minh,median);
        ans.push_back(median);
    }
    return ans;
}

int main(){
    vector<int>arr={3,10,4,9,5,1,2,6,7,8};
    vector<int>ans=findmedian(arr,5);
    for(auto itr:arr) cout<<itr<<" ";
    cout<<"\nPrinting the median of the given array-->\n";
    for(auto itr:ans) cout<<itr<<" ";

    return 0;
}