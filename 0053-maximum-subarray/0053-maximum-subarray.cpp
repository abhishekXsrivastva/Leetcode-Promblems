class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long maxRes = LLONG_MIN;
        long long sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxRes = max(maxRes, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxRes;
    }
};