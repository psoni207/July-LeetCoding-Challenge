class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == k){
            return nums;
        }
        
        sort(nums.begin(), nums.end());
        
        vector<int> res;
        int n = nums.size();
        int x = nums[0];
        int pos = 0;
        
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b){
            return a.second < b.second;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp) > PQ(cmp);
        
        for(int i = 0; i < n; i += 1){
            if(nums[i] != x){
                PQ.push({x, i-pos});
                x = nums[i];
                pos = i;
            }
        }
        PQ.push({nums[n-1],n-pos});
        
        for(int i = 0; i < k; i += 1){
            res.push_back(PQ.top().first);
            PQ.pop();
        }

        return res;
        
    }
};