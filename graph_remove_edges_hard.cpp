class UnionBySize{
    vector<int>unions, Size;
    int comp;
public:
    UnionBySize(int n){
        unions.resize(n+1);
        Size.resize(n+1,1);
        comp = n;
        for(int i=0;i<n;i++)unions[i] = i;
    }
    int Find(int x){
        if(x==unions[x]) return x;
        return unions[x] = Find(unions[x]);
    }
    
    bool Union(int x,int y){
        int elem1 = Find(x);
        int elem2 = Find(y);
        if(elem1 == elem2) return 0;
        if(Size[elem1]>Size[elem2]){
            Size[elem1] += Size[elem2];
            unions[elem2] = elem1;
        }else{
            Size[elem2] += Size[elem1];
            unions[elem1] = elem2;
        }
        comp--;
        return 1;
    }
    bool isConnect(){
        return comp == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionBySize alice(n),bob(n);
        int edge = 0;
        for(auto it: edges){
            if(it[0] == 3){
                edge += (alice.Union(it[1],it[2]) | bob.Union(it[1],it[2]));
            }
        }

        for(auto it: edges){
            if(it[0] == 1) edge += alice.Union(it[1],it[2]);
            else if(it[0] == 2) edge += bob.Union(it[1],it[2]);
        }

        if(alice.isConnect() && bob.isConnect()){
            return edges.size()-edge;
        }
        return -1;
    }
};
