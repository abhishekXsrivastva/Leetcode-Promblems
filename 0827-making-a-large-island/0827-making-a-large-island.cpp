class DisjoinedSet{
public:
   vector<int> parent;
   vector<int> size;

   DisjoinedSet(int n){
    size.resize(n+1, 1);
    parent.resize(n+1);
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
   }

   int findParent(int node){
    if(parent[node] == node) return node;

    return parent[node] = findParent(parent[node]);
   }

   void unionBySize(int u, int v){
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);

    if(ulp_u == ulp_v) return;

    if(size[ulp_u] < size[ulp_v]){
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    }else{
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
   }
};
class Solution {
    bool isValid(int newr, int newc, int n){
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjoinedSet dsu(n*n);
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;
                int dr [] = {-1, 0, 1, 0};
                int dc [] = {0, 1, 0, -1};
                for(int i = 0; i < 4; i++){
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        dsu.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        int largestIsland = 0;
   
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;
                set<int> parentComp;
                int dr [] = {-1, 0, 1, 0};
                int dc [] = {0, 1, 0, -1};
                 for(int i = 0; i < 4; i++){
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                if(isValid(newr, newc, n)){
                    if(grid[newr][newc] == 1){
                        parentComp.insert(dsu.findParent(newr * n + newc));
                    }
                }
            }
            
        
        int totalSize = 0;
        for(auto it : parentComp){
            totalSize += dsu.size[it];
        }
        largestIsland = max(largestIsland, totalSize + 1);
        }
        }

        for(int i = 0; i < n*n; i++){
            largestIsland = max(largestIsland, dsu.size[dsu.parent[i]]);
        }
        return largestIsland;
    }
};