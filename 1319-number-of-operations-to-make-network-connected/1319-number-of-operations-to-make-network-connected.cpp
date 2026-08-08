class DisjoinedSet {
    public:
    vector<int> parent, size;
    DisjoinedSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node] == node) return node;

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjoinedSet dsu(n);
        int cntExtras = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(dsu.findParent(u) == dsu.findParent(v)) {
            cntExtras++;
            }else{
                dsu.unionBySize(u, v);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(dsu.parent[i] == i) {
                cnt++;
            }
        }
        int res = cnt - 1;
        if(cntExtras >= res) {
            return res;
        }
        return -1;
    }
};