class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0){
            return false;
        }

        int grps = n / k;

        unordered_map<int, int> mpp;
        for(int num : nums){
            mpp[num]++;

            if(mpp[num] > grps){
                return false;
            }
        }
        return true;
    }
};