class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++, r--;
        }
        return true;
    }
    void partitionHelper(int idx, vector<string>& curr,
                         vector<vector<string>>& res, string& s) {
        if (idx == s.length()) {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                partitionHelper(i + 1, curr, res, s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;

        partitionHelper(0, curr, res, s);

        return res;
    }
};