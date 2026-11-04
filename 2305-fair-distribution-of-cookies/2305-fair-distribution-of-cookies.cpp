class Solution {
public:
    int n;
    void distributeCookiesHelper(int idx, vector<int>& curr, vector<int>& cookies, int k, int &res){
        if(idx == n) {
            int unfairness = *max_element(begin(curr), end(curr));
            res = min(res, unfairness);
            return;
        }
        for(int i = 0; i < k; i++) {
            curr[i] += cookies[idx];
            distributeCookiesHelper(idx+1, curr, cookies, k, res);
            curr[i] -= cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        int res = INT_MAX;
        vector<int> curr(k, 0);

        distributeCookiesHelper(0, curr, cookies, k, res);
        return res;

    }
};