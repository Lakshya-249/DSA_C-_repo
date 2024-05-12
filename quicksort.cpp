#include<bits/stdc++.h>
#include<vector>
using namespace std;

int pivotindex(vector<int>&vec,int low,int high){
    int pivot=vec[low];
    int x=low;
    int y=high;

    while(x<y){
        while(pivot>=vec[x] && x<=high-1){
            x++;
        }
        while(pivot<vec[y] && y>=low+1){
            y--;
        }
        if(x<y){
            swap(vec[x],vec[y]);
        }
    }
    swap(vec[low],vec[y]);
    return y;
}

void qs(vector<int>&vec,int low, int high){
    if(low<high){
        int pindex = pivotindex(vec,low,high);
        qs(vec,low,pindex-1);
        qs(vec,pindex+1,high);
    }
}

void quicksort(vector<int>&vec){
    qs(vec,0,vec.size()-1);
}

int main(){
    vector<int>vec={8,4,1,3,5,2,6,7,2,9};
    for(auto it:vec) cout<<it<<" ";
    cout<<endl;
    quicksort(vec);
    for(auto it:vec) cout<<it<<" ";
    return 0;
}