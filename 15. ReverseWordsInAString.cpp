class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
    
        int n = s.length();
        
        int i = 0;
        while(i < n)
        {
            string str = "";
            if(s[i]!=' '){
                while(s[i]!=' ' && s[i]!='\0'){
                    str+=s[i++];
                }
                words.push_back(str);
            }
            else{
                i += 1;
            }
        }


        int m = words.size();
        string A = "";
        for(int i = m-1; i >= 0; i -= 1)
        {
            int len = words[i].length();
            for(int j = 0; j < len; j += 1){
                A += words[i][j];
            }
            if(i != 0){
                A += ' ';
            }
        }
        
        return A;

    }
};