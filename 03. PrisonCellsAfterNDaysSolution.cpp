class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        unordered_map<string, int> umap;
        
        for(int i = 0; i < N; ++i){
            string s(cells.begin(), cells.end());
            
            if(umap.find(s) != umap.end()){
                int loop_len = i- umap[s];
                int rem_days = (N-i) % loop_len;
                return prisonAfterNDays(cells, rem_days);
            }else{
                umap.insert({s,i});
                
                int prev = cells[0];
                for(int j = 1; j < 7; ++j){
                    int next = cells[j+1];
                    int curr = cells[j];
                    
                    cells[j] = (prev == next);
                    prev = curr;
                }
            }
            
            cells[0] = 0;
            cells[7] = 0;
        }
        
        return cells;
        
    }
};