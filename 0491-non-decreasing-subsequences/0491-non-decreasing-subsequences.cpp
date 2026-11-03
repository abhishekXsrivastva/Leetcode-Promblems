class Solution {
public:
    void findSubsequencesHelper(int idx, vector<int>& curr, vector<int>& nums,
                                vector<vector<int>>& res) {
        int n = nums.size();
        if (curr.size() >= 2) {
            res.push_back(curr);
        }
        unordered_set<int> st;
        for (int i = idx; i < n; i++) {
            if ((curr.empty() || nums[i] >= curr.back()) &&
                (st.find(nums[i]) == st.end())) {
                curr.push_back(nums[i]);
                findSubsequencesHelper(i + 1, curr, nums, res);
                curr.pop_back();
                st.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;

        findSubsequencesHelper(0, curr, nums, res);

        return res;
    }
};