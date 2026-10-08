class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        for(int num : arr){
            pq.push({abs(num - x), num});
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};