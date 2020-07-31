class Solution {
    private:
    int* fib;
    
public:
    Solution(){
        int N = 45;
        fib = new int[N+1];
        fib[0] = 1;
        fib[1] = 1;
        for(int i = 2; i <= N; i++){
            fib[i] = fib[i-1] + fib[i-2];
        }
    }
    
    int climbStairs(int n) {
        return fib[n];
        
    }
};