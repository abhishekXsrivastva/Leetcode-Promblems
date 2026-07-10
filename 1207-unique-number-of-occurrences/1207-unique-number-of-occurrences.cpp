class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(int num : arr){
            mpp[num]++;
        }

        unordered_set<int> seen;

        for(auto &it : mpp){
            int unique = it.second;
            if(seen.count(unique)){
            return false; 
            }
             seen.insert(unique);
        }
        return true;
       
    }
};