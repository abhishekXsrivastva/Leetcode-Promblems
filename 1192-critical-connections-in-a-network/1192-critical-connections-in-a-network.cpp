class Solution {
public:
    vector<int> tin, low;
    int timer = 1;
    vector<vector<int>> criticalNetwork;
    
    void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, vis, adj);
                if(low[it] > tin[node]){
                  criticalNetwork.push_back({it, node});
                }
                low[node] = min(low[node], low[it]);
              } else{
                    low[node] = min(low[node], tin[it]);
                }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        tin.resize(n);
        low.resize(n);

        vector<int> vis(n, 0);
        dfs(0, -1, vis, adj);

        return criticalNetwork;
    }
};