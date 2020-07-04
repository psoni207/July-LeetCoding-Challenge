class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0){
            return n;
        }
        
        vector<int> res;
        res.push_back(1);
        
        int i = 0;
        int j = 0;
        int k = 0;
        while(res.size() != n){
            int a = res[i]*2;
            int b = res[j]*3;
            int c = res[k]*5;
            
            int min_num = min( min(a, b), c);
            res.push_back(min_num);
            
            if(a == min_num){
                i += 1;
            }
            if(b == min_num){
                j += 1;
            }
            if(c == min_num){
                k += 1;
            }
        }
        
        return res[n-1];
    }
};