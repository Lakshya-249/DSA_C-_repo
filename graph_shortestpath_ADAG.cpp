#include<bits/stdc++.h>

using namespace std;

class graph{
    private:
        int n,m;
        vector<int>*arr;
    public:
        graph(int n,int m){
            this->n=n;
            this->m=m;
            arr= new vector<int>[n+1];
        }

        vector<int>* create_graph(){
            cout<<"Enter the data: ";
            for(int i=0;i<m;i++){
                int u,v;
                cin>>u>>v;
                arr[u].push_back(v);
                arr[v].push_back(u);
            }
        }

        void display(){
            for(int i=0;i<n+1;i++){
                cout<<i<<" : ";
                for(auto it: arr[i]){
                    cout<<it<<" ";
                }
                cout<<endl;
            }
        }

        vector<int> shortestpath(int src){
            vector<int>distance(n+1,INT_MAX);
            distance[src]=0;
            queue<int>q;
            q.push(src);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it: arr[node]){
                    if(distance[node]+1 < distance[it]){
                        distance[it]=distance[node]+1;
                        q.push(it);
                    }
                }
            }
            return distance;
        }
};

int main(){
    graph g1(8,11);
    vector<int>* arr=g1.create_graph();
    g1.display();
    vector<int>distance = g1.shortestpath(4);
    for(int i=0;i<=8;i++){
        cout<<i<<" : "<<distance[i]<<endl;
    }
    return 0;
}

// 0 1
// 0 3
// 1 2
// 2 6
// 3 4
// 4 5
// 5 6
// 6 7
// 6 8
// 7 8
// 2 4