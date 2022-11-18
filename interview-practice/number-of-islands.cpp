//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void bfs(vector<vector<char>>grid,vector<vector<int>>&vis,int r,int c){
      queue<pair<int,int>>q;
      int m=grid.size();
      int n=grid[0].size();
      vis[r][c]=1;
      q.push({r,c});
      while(!q.empty()){
          int row=q.front().first;
          int col=q.front().second;
          q.pop();
          for(int drow=-1;drow<=1;drow++){
              for(int dcol=-1;dcol<=1;dcol++){
                  int nrow=row+drow;
                  int ncol=col+dcol;
                  if(nrow>=0 and nrow<m && ncol>=0 && ncol<n and !vis[nrow][ncol] and grid[nrow][ncol]=='1'){
                      q.push({nrow,ncol});
                      vis[nrow][ncol]=1;
                  }
              }
          }
      }
  }

  void dfs(vector<vector<char>>grid,vector<vector<int>>&vis,int row,int col){
        int m=grid.size();
        int n=grid[0].size();
      vis[row][col]=1;
         for(int drow=-1;drow<=1;drow++){
              for(int dcol=-1;dcol<=1;dcol++){
                  int nrow=row+drow;
                  int ncol=col+dcol;
                  if(nrow>=0 and nrow<m && ncol>=0 && ncol<n and !vis[nrow][ncol] and grid[nrow][ncol]=='1'){
                      vis[nrow][ncol]=1;
                      dfs(grid,vis,nrow,ncol);
                  }
              }
          }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        int ct=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ct++;
                    bfs(grid,vis,i,j);
                }
            }
        }  
        return ct;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends