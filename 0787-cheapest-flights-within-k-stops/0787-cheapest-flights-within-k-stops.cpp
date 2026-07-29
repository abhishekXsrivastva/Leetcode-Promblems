class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto e : flights){
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto neigh : adj[node]){
                int adjNode = neigh.first;
                int price = neigh.second;
                
                if(cost + price < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + price;
                    q.push({stops + 1, {adjNode, cost + price}});
                }

            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};