class Solution {
    public:
        vector<vector<int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
            int bfs(vector<vector<int>>& grid,int val,int m ,int n){
                queue<pair<int,int>>q;
                vector<vector<bool>>visited(m,vector<bool>(n,false));
                visited[0][0]=true;
                q.push({0,0});
                int points = 0;
                while(!q.empty()){
                    int N = q.size();
                    while(N--){
                        auto[i,j]=q.front();
                        q.pop();
                        if(grid[i][j] >val){
                            continue;
                        }
                        points++;
                        for(auto &dir: directions){
                            int i_ = i+dir[0];
                            int j_ = j+dir[1];
                            if(i_>=0 && j_>=0 && i_<m && j_<n && !visited[i_][j_] && grid[i_][j_]<val){
                                q.push({i_,j_});
                                visited[i_][j_]=true;
                            } 
                        }
                    }
                }
                return points;
            }
            int dfs(vector<vector<int>>& grid,int i,int j ,int m ,int n ,vector<vector<bool>> &visited,int val){
                if(i<0 || j<0||i>=m||j>=n|| visited[i][j] || grid[i][j]>=val){
                    return 0;
                }
                visited[i][j]=true;
                int points = 1;
                for(auto& dir : directions){
                    int i_ = i+dir[0];
                    int j_ = j+dir[1];
                    points+=dfs(grid,i_,j_,m,n,visited,val);
                }
                return points;
            }
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m=grid.size();
            int n = grid[0].size();
            int q = queries.size();
            vector<int>result(q,0);
            for(int i =0;i<q;i++){
                vector<vector<bool>>visited(m,vector<bool>(n,false));
                result[i] = dfs(grid,0,0,m,n,visited,queries[i]);
            }
            return result;
        }
    };