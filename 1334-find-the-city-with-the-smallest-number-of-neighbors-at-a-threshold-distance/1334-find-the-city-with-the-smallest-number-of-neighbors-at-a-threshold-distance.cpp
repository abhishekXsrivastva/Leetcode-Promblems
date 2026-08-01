class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
      /*  vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for(auto it : edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for(int i = 0; i < n; i++) dist[i][i] = 0;

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;

                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
        int minCity = n+1;
        int cityNo = -1;

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                }
                }
                if(cnt <= minCity){
                    minCity = cnt;
                    cityNo = i;
            }
        }
        return cityNo; */

           vector<vector<pair<int, int>>> adj(n);
        for(auto e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        int minCity = 1e9;
        int res = -1;
        
        for(int src = 0; src < n; src++){
            vector<int> dist(n, 1e9);
            dist[src] = 0;
            
            priority_queue<pair<int,int>,
                           vector<pair<int, int>>,
                           greater<pair<int, int>>> pq;
            
            pq.push({0, src});
            
            while(!pq.empty()){
                auto it = pq.top();
                pq.pop();
                int dis = it.first;
                int node = it.second;
                
                if(dis > dist[node]) continue;
                
                for(auto it : adj[node]){
                    int adjNode = it.first;
                    int wt = it.second;
                    
                    if(dis + wt < dist[adjNode]){
                        dist[adjNode] = dis + wt;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(src != i && dist[i] <= distanceThreshold){
                    cnt++;
                }
            }
            
            
            if(cnt <= minCity){
                minCity = cnt;
                res = src;
            }
           
        }
        return res;
    }
};
