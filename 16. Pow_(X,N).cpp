class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0)
            return 1;
        
        double ans;
        ans=power(x,n);
        if(n<0)
            return 1/ans;
        else
            return ans;
        
        
    }
    
    
    double power(double a,int b)
    {
	    if(b==0)
		    return 1;
	    else
	    {
		    double x;
		    x=( power(a,b/2) );
            
		    if(b%2==0)
		    	return x*x;
		    else
			    return x*x*a;
	    }
    }
};