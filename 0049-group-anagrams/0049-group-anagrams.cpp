class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for(auto& s : strs){
            vector<int> count(26,0);
            for(char c : s){
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 1; i < 26; i++){
                key += ',' + to_string(count[i]);
            }
            mpp[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto& it : mpp){
            res.push_back(it.second);
        }
        return res;
    }
};