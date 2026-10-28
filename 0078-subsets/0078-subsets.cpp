class Solution {
public:
    void subsetsHelper(vector<int>& curr, int i, vector<int>& nums, vector<vector<int>>& res) {
        if(i >= nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        subsetsHelper(curr, i+1, nums, res);
        curr.pop_back();
        subsetsHelper(curr, i+1, nums, res);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> curr;
        subsetsHelper(curr, 0, nums, res);
        return res;

    }
};