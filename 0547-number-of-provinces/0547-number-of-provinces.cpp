class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
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
        int v = isConnected.size();
        DisjointSet dsu(v);
        for(int row = 0; row < v; row++){
            for(int col = 0; col < v; col++){
                if(isConnected[row][col] == 1){
                    dsu.unionBySize(row, col);
                }
            }
        }
        int numProvinces{0};
        for(int i = 0; i < v; i++){
            if(dsu.findParent(i) == i) numProvinces++;
        }

        return numProvinces;

    }
};