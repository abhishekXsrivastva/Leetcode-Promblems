class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int n : nums){
            mpp[n] = 1 + mpp[n];
        }

        vector<vector<int>> freq(nums.size() + 1);
        for(const auto &it : mpp){
            freq[it.second].push_back(it.first);
        }

        vector<int> res;
        for(int i = freq.size() - 1; i >= 0; i--){
            for(int n : freq[i]){
                res.push_back(n);
                if(res.size() == k){
                return res;
            }
            }
        }
        return res;

    }
};