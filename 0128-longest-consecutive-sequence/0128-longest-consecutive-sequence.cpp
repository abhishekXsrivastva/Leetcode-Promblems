class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int res = 1;
        unordered_set<int> st;

        for(int num : nums){
            st.insert(num);
        }

        for(auto& it : st){
            if(st.find(it-1) == st.end()){
                int x = it;
                int cnt = 1;

                while(st.find(x+1) != st.end()){
                    x += 1;
                    cnt += 1; 
                }
                 res = max(res, cnt);
            }  
        }
        return res;
    }
};