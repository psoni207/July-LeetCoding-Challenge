class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adj(numCourses);
        int n = prerequisites.size();
        
        for(int i = 0; i < n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> s;
        vector<int> visited(numCourses,0);
        
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0 && dfs(i, adj, s, visited) ){
                return {};
            }
        }
        
        reverse(s.begin(), s.end());
        return s;
        
    }
    
    bool dfs(int u, vector<vector<int> > &adj, vector<int> &s, vector<int> &visited){
        visited[u] = 1;
        
        for(auto v: adj[u]){
            if(visited[v] == 1){
                return true;
            }
            if(visited[v] == 0 && dfs(v, adj, s, visited)){
                return true;
            }
        }
        
        visited[u] = 2;
        s.push_back(u);
        return false;
    }
};