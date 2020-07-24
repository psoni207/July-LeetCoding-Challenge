class Solution {
    vector<vector<int> > res;
    int n;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<int> > adj(n);
        
        int u = 0;
        for(vector<int> &vec : graph){
            for(int v: vec){
                adj[u].push_back(v);
            }
            u += 1;
        }
        
        vector<int> path;
        
        vector<bool> visited(n, false);
        helperFindPath(0, adj, visited, path);
        
        return res;
        
    }
    
    void helperFindPath(int u, vector<vector<int> > &adj,vector<bool> &visited, vector<int> &path){
        visited[u] = true;
        path.push_back(u);
        
        if(u == n-1){
            res.push_back(path);
        }
        else{
            for(int v: adj[u]){
                if(visited[v] == false){
                    helperFindPath(v, adj, visited, path);
                }
            }
        }
        
        visited[u] = false;
        path.pop_back();
    }
};