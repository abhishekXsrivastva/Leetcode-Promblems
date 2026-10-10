class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int num : nums){
            mpp[num]++;
        }

        vector<vector<int>> freq(nums.size() + 1);
            for(auto &it : mpp){
                freq[it.second].push_back(it.first);
            }
            vector<int> res;
            for(int i = freq.size() - 1; i >= 0; i--){
                for(int ele : freq[i]){
                    res.push_back(ele);
                    if(res.size() == k){
                        return res;
                    }
                }
            }
        
        return res;
    } 
};