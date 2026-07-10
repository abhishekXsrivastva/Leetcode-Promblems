class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(int num : arr){
            mpp[num]++;
        }

        unordered_set<int> seen;

        for(auto &it : mpp){
            int duplicate  = it.second;
            if(seen.count(duplicate)){
            return false; 
            }
             seen.insert(duplicate);
        }
        return true;
       
    }
};