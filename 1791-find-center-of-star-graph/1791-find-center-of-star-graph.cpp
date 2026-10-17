class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n+1, 0);
        queue<int> q;
        q.push(edges[0][0]);
        vis[edges[0][0]] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(adj[node].size() == n-1) {
                return node;
            }
            for(auto &it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return -1;
    }
};