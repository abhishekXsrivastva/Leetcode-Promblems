class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathvis, vector<int>& terminal, vector<vector<int>>& graph){
          vis[node] = 1;
          pathvis[node] = 1;
          terminal[node] = 0;

          for(auto &it : graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathvis, terminal, graph) == true){
                    terminal[node] = 0;
                    return true;
                }
            }else if(pathvis[it]){
                terminal[node] = 0;
                return true;

            }
          }
          terminal[node] = 1;
          pathvis[node] = 0;
          return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v, 0);
        vector<int> pathvis(v, 0);
        vector<int> terminal(v,0);
        vector<int> safeNodes;

        for(int i = 0; i < v; i++){
            if(!vis[i]){
                dfs(i, vis, pathvis, terminal, graph);
            }
        }

        for(int i = 0; i < v; i++){
            if(terminal[i] == 1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};