class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        vector<int> res;
        
        if(n == 1){
            if(digits[0] != 9){
                res.push_back(digits[0] + 1);
            }else{
                res.push_back(1);
                res.push_back(0);
            }
            
            return res;
        }
        
        int carry = 1;
        for(int i = n-1; i >= 0; i--){
            if(carry + digits[i] == 10){
                res.push_back(0);
            }else{
                res.push_back(digits[i] + carry);
                carry = 0;
            }
        }
        if(carry){
            res.push_back(carry);
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
};