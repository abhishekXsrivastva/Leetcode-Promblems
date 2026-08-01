class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto e : times){
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;
            
            if(dis > dist[node]) continue;
            for(auto it : adj[node]){
                int adjList = it.first;
                int wt = it.second;

                if(dis + wt < dist[adjList]){
                    dist[adjList] = dis + wt;
                    pq.push({dist[adjList], adjList});
                }
            }
        }

        int res = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;

            res = max(res, dist[i]);
        }
        return res;
    }
};