class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 1){
            return n;
        }
        
        long num = n;
        long sum = sqrt(1 + 8*num);
        sum -= 1;
        
        long res = sum / 2;
        
        return (int)(res); 
    }
};