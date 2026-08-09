class DSU{
public:
vector<int> parent, size;
DSU(int n){
    size.resize(n+1, 1);
    parent.resize(n+1);
    for(int i = 0; i <= n; i++){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string, int> mpp;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail] = i;
                }else{
                    ds.unionBySize(i, mpp[mail]);
                }
            }
        }

        vector<vector<string>> mergeMails(n);
        for(auto it : mpp){
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergeMails[node].push_back(mail);
        }

        vector<vector<string>> res;
        for(int i = 0; i < n; i++){
            if(mergeMails[i].size() == 0) continue;
            sort(mergeMails[i].begin(), mergeMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMails[i]){
                temp.push_back(it);
            }
            res.push_back(temp);

        }

        return res;
        
    }
};