class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        int diff = n/2;
        unordered_set<int> st;
        for(int num : candyType){
            st.insert(num);
            if(st.size() == diff)
            break;
        }
        return st.size();
    }
};