class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        mpp[0] = 1;
        int preSum = 0;
        int res = 0;
        for(int num : nums){
            preSum += num;
            res += mpp[preSum - k];
            mpp[preSum] +=  1;
        }
        return res;
    }
};