class Solution {
public:
    string addBinary(string a, string b) {
        
        string sum = "";
        
        int n,m,i;
        n = a.length();
        m = b.length();
        if(m>n)
            return addBinary(b,a);
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        char carry = '0';
        for(i = 0; i < m; i++){
            if(a[i] == '1' && b[i] == '1'){
                if(carry == '1'){
                    sum += '1';
                }else{
                    sum += '0';
                    carry = '1';
                }
            }else if(a[i] == '0' && b[i] == '0'){
                if(carry == '1'){
                    sum += '1';
                    carry = '0';
                }else{
                    sum += '0';
                }
            }else {
                if(carry == '1'){
                    sum += '0';
                }else{
                    sum += '1';
                }
            }
        }
        
        for(i = m; i < n; i++)
        {
            if(carry == '1' ){
                if(a[i] == '1'){
                    sum += '0';
                }else{
                    sum += '1';
                    carry = '0';
                }
            }
            else{
                sum += a[i];
            }
        }
        if(carry == '1'){
            sum += '1';
        }
        
        reverse(sum.begin(), sum.end());
        
        return sum;
    }
};