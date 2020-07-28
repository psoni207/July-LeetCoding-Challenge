class Solution {
    private:
    const int MAX_TYPE = 26;
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int total_tasks = tasks.size();
        
        vector<int> freq(MAX_TYPE, 0);
        
        for(char c: tasks) {
            freq[c-'A'] += 1;
        }
        
        sort(freq.begin(), freq.end());
        
        int max = freq[MAX_TYPE-1] -1;
        int idleInterval = max*n;
        
        for(int i = MAX_TYPE - 2; i >= 0; i--) {
            idleInterval = idleInterval - min(max,freq[i]);
        }
        
        return idleInterval > 0 ? idleInterval + total_tasks : total_tasks;
        
    }
};