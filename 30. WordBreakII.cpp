class Solution {
    private:
    unordered_set<string> uset;
    vector<string> res;
    int n;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        n = s.size();
        
        /*
        for(string word: wordDict){
            uset.insert(word);
        }
        
        string word = "";
        string ans = "";
        
        helper(s, 0, word, ans);
        
        return res;
        */
        
        unordered_map<string, vector<string> > umap;
        return wordBreakHelper(s, wordDict, umap);
    }
    
    /*
    void helper(string &s, int pos, string word, string ans){
        if(pos == n){
            res.push_back(ans);
            ans = "";
        }
        
        while(pos < n ){
            word += s[pos];
            if(uset.find(word) != uset.end() ){
                if(pos != n-1){
                    helper(s, pos+1, "", ans + word + " ");
                    //ans += word + " ";
                }else{
                    helper(s, pos+1, "", ans + word);
                    //ans += word;
                }
            }
            pos += 1;
        }
    }
    */
    
    vector<string> wordBreakHelper(string s, vector<string> &wordDict, unordered_map<string, vector<string> > &umap){
        if(umap.find(s) != umap.end()){
            return umap[s];
        }
        vector<string> results;
        
        if(s.size() == 0){
            //Base Case
            results.push_back("");
            return results;
        }
        
        for(string word: wordDict){
            if( s.size() >= word.size() && s.substr(0, word.size()) == word ){
                string sub = s.substr(word.size());
                vector<string> subStrings = wordBreakHelper(sub, wordDict, umap);
                
                for(string subString: subStrings){
                    string optionalSpace = subString.empty() ? "" : " ";
                    results.push_back(word + optionalSpace + subString);
                }
            }
        }
        
        umap.insert({s, results});
        return results;     
    }
};