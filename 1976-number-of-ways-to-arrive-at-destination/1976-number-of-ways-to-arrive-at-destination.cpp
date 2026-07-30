class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = (int)(1e9 + 7);
        vector<vector<pair<int, int>>> adj(n);
        for(auto e : roads){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;
         pq.push({0,0});

         vector<long long> dist(n, LLONG_MAX);
         dist[0] = 0;
         vector<int> ways(n);
         ways[0] = 1;

         while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dis + wt < dist[adjNode]){
                dist[adjNode] = dis + wt;
                ways[adjNode] = ways[node];
                pq.push({dist[adjNode], adjNode});
            }else if(dis + wt == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
         }
    }

         return ways[n-1] % mod;              
    }
};