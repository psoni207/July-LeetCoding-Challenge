class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> A(s.begin(),s.end());
        
        long n = A.size();
        
        vector<vector<int> > res;
        for(long i = 0; i < pow(2,n); i++){
            
            vector<int> temp;
            for(long j = 0; j < n; j++){
                if(i & (1 << j) ){
                    temp.push_back(A[j]);
                }
            }
            res.push_back(temp);
        }
        
        return res;
        
    }
};