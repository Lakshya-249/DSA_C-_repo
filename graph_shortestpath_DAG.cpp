#include<bits/stdc++.h>

using namespace std;

class graph{
    private:
        int n,m;
        vector<pair<int,int>>*arr;
    public:
        graph(int n,int m){
            this->n=n;
            this->m=m;
            arr= new vector<pair<int,int>>[n+1];
        }

        vector<pair<int,int>>* create_DAG(){
            cout<<"Enter the weight and 2 vertice: ";
            for(int i=0;i<m;i++){
                int u,v,w;
                cin>>u>>v>>w;
                arr[u].push_back({v,w});
            }
            return arr;
        }

        void display(){
            for(int i=0;i<n+1;i++){
                cout<<i<<" : ";
                for(auto it: arr[i]){
                    cout<<"{"<<it.first<<","<<it.second<<"} ";
                }
                cout<<endl;
            }
        }        
};

class topsort{
    public:
        queue<int> toposort(vector<pair<int,int>>arr[],int n){
            int indegree[n+1]={0};
            for(int i=0;i<n+1;i++){
                for(auto it: arr[i]){
                    indegree[it.first]++;
                }
            }
            queue<int>q;
            for(int i=0;i<n+1;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            queue<int>ans;
            while(!q.empty()){
                int node=q.front();
                ans.push(node);
                q.pop();
                for(auto it: arr[node]){
                    indegree[it.first]--;
                    if(!indegree[it.first]){
                        q.push(it.first);
                    }                       
                }
            }
            return ans;
        }
     
        vector<int> shortest_path(vector<pair<int,int>>arr[],int n){
            vector<int>distance(n+1);
            for(int i=0;i<n+1;i++)distance[i]=INT_MAX;
            queue<int>tops= toposort(arr,n);
            distance[tops.front()]=0;
            while(!tops.empty()){
                int i=tops.front();
                tops.pop();
                for(auto it: arr[i]){
                    int v=it.first;
                    int wt=it.second;
                    if(distance[i]+ wt< distance[v]){
                        distance[v]= distance[i]+wt;
                    }
                }
            }
            return distance;
        }
};

int main(){
    graph g1(6,8);
    vector<pair<int,int>>*arr= g1.create_DAG();
    for(int i=0;i<7;i++){
                cout<<i<<": ";
                for(auto it: arr[i]){
                    cout<<"{"<<it.first<<","<<it.second<<"} ";
                }
                cout<<endl;
            }
    // g1.display();
    // topsort t1;
    // queue<int>st=t1.toposort(arr,6);
    // while(!st.empty()){
    //     cout<<st.front()<<" ";
    //     st.pop();
    // }
    // cout<<endl;
    // vector<int>ans=t1.shortest_path(arr,6);
    // for(int i=0;i<=6;i++){
    //     cout<<i<<" : "<<ans[i];
    //     cout<<endl;
    // }


    return 0;
}
// 6 4 2
// 5 4 1
// 4 0 3
// 4 2 1
// 0 1 2
// 1 3 1
// 2 3 3
// 6 5 3