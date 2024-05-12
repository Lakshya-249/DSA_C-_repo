#include<bits/stdc++.h>

using namespace std;

class dijkstra{
    public:
        int min_step_multiply(vector<int>arr,int start,int end){
            vector<int>dist(1e5,1e9);
            int mod= 1e5;
            queue<pair<int,int>>q;
            q.push({0,start});
            dist[start]=0;
            while(!q.empty()){
                int node= q.front().second;
                int steps= q.front().first;
                q.pop();
                for(auto it: arr){
                    int num= (it*node)%mod;
                    if(steps+1<dist[num]){
                        dist[num]=steps+1;
                        if(num == end)return steps+1;
                        q.push({steps+1,num});
                    }
                }
            }
            return -1;
        }
};

int main(){
    vector<int>arr={2,5,7};
    int start=3;
    int end=2100;
    dijkstra dj1;
    int ans= dj1.min_step_multiply(arr,start,end);
    cout<<"The minimum multiplication steps required for following array is: "<<ans;

    return 0;
}