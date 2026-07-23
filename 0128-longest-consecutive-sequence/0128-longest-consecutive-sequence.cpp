class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int res = 1;
        unordered_set<int> st;
        for(int num : nums){
            st.insert(num);
        }

        for(auto i : st){
            if(st.find(i - 1) == st.end()){
                int x = i;
                int cnt = 1;
                while(st.find(x+1) != st.end()){
                    x = x + 1;
                    cnt++;
                }
                res = max(cnt, res);
            }
        }
        return res;
    }
};