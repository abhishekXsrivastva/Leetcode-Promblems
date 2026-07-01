class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto &e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);
        int cnt_comp = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                queue<int> q; 
                q.push(i);
                vis[i] = 1;
                int nodes = 0;
                int degreeSum = 0;
               while(!q.empty()){
                int node = q.front();
                q.pop();
                nodes++;
                degreeSum += adjList[node].size();
                for(auto &neigh : adjList[node]){
                    if(!vis[neigh]){
                        vis[neigh] = 1;
                        q.push(neigh);
                    }
                }
               }
               int edgeCnt = degreeSum / 2;
               if(edgeCnt == (nodes *(nodes - 1 ))/2)
               cnt_comp++;
            }
        }
        return cnt_comp;
    }
};