class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int red = 0;
        int white = 0;
        int blue = 0;
        for(int i = 0; i < size; i++){
            if(nums[i] == 0) {
                red++;
            }
            else if(nums[i] == 1) {
                white++;
                }
            else{
                blue++;
            }
        }
        int idx = 0;
        while(red--){
            nums[idx++] = 0;
        }
        while(white--){
            nums[idx++] = 1;
        }
        while(blue--){
            nums[idx++] = 2;
        }
    }
};