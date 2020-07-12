class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t res = 0;
        const int total_bits = 32;
        
        for(int i = 0; i < total_bits; i++){
            if(n & (1 << i)){
                res |= 1 << ((total_bits-1) -i);
            }
        }
        
        return res;
        
    }
};