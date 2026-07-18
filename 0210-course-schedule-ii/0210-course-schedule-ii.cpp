class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>res;

        vector<vector<int>> adj(numCourses);

        for(auto e : prerequisites){
            adj[e[1]].push_back(e[0]);
        }

        vector<int>inDegree(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++){
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node  = q.front();
            q.pop();
            res.push_back(node);

            for(auto neigh : adj[node]){
                inDegree[neigh]--;
                if(inDegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        if(res.size() == numCourses) return res;

        return {};

    }
};