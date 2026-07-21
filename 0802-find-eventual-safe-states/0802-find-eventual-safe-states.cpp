class Solution {
public:
    // bool dfs(int node, vector<int>& vis, vector<int>& pathvis, vector<int>& terminal, vector<vector<int>>& graph){
    //       vis[node] = 1;
    //       pathvis[node] = 1;
    //       terminal[node] = 0;

    //       for(auto &it : graph[node]){
    //         if(!vis[it]){
    //             if(dfs(it, vis, pathvis, terminal, graph) == true){
    //                 terminal[node] = 0;
    //                 return true;
    //             }
    //         }else if(pathvis[it]){
    //             terminal[node] = 0;
    //             return true;

    //         }
    //       }
    //       terminal[node] = 1;
    //       pathvis[node] = 0;
    //       return false;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         
         int v = graph.size();
         vector<vector<int>> revAdj(v);
         vector<int> inDegree(v);

         for(int i = 0; i < v; i++){
            for(auto it : graph[i]){
                revAdj[it].push_back(i);
                inDegree[i]++;
            }
         }

         vector<int> safeNodes;
         queue<int> q;

         for(int i = 0; i < v; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
         }

         while(!q.empty()){
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);

            for(auto it : revAdj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
         }

          sort(safeNodes.begin(), safeNodes.end());

         return safeNodes;







        // int v = graph.size();
        // vector<int> vis(v, 0);
        // vector<int> pathvis(v, 0);
        // vector<int> terminal(v,0);
        // vector<int> safeNodes;

        // for(int i = 0; i < v; i++){
        //     if(!vis[i]){
        //         dfs(i, vis, pathvis, terminal, graph);
        //     }
        // }

        // for(int i = 0; i < v; i++){
        //     if(terminal[i] == 1){
        //         safeNodes.push_back(i);
        //     }
        // }
    }
};