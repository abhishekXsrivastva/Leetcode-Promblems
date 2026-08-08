
class DisjoinedSet{
    public:
    vector<int> parent, size;
    DisjoinedSet(int n){
        parent.resize(n+1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        size.resize(n+1, 1);
    }

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V = isConnected.size();
        DisjoinedSet dsu(V);
        for(int i = 0; i < V; i++){
            for(int j = i+1; j < V; j++){
                if(isConnected[i][j] == 1){
                dsu.unionBySize(i, j);
                }
            }
        }
        int res = 0;
         for(int i = 0; i < V; i++){
            if(dsu.parent[i] == i) res++;
         }

         return res;
    }
};