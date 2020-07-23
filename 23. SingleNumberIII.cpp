class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        int _xor = 0;
        for(int num: nums){
            _xor ^= num;
        }
        
        int first_set_bit = 0;
        int temp = _xor;
        while(temp){
            if(temp & 1){
                break;
            }
            first_set_bit += 1;
            temp = temp >>1;
        }
        
        int xor_set = 0;
        int xor_unset = 0;
        
        for(int num: nums){
            if(num & (1 << first_set_bit) ){
                xor_set ^= num;
            }else{
                xor_unset ^= num;
            }
        }
        
        vector<int> res(2);
        res[0] = xor_set;
        res[1] = xor_unset;
        
        return res;
    }
};