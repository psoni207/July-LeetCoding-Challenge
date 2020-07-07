class Solution {
    private:
    int m, n;
    const int _dir = 4;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int res = 0;
        for(int i = 0; i < m; i += 1){
            for(int j = 0; j < n; j += 1){
                if(grid[i][j] == 1){
                    if(i == 0 ) res += 1;
                    if(j == 0 ) res += 1;
                    if(i == m-1 ) res += 1;
                    if(j == n-1 ) res += 1;
                    
                    for(int k = 0; k < _dir; k += 1){
                        int x = i + dir[k][0];
                        int y = j + dir[k][1];
                        
                        if(x >=0 && y >= 0 && x < m && y < n){
                            if(grid[x][y] == 0){
                                res += 1;
                            }
                        }
                    }
                    
                }
            }
        }
        
        return res;
    }
};