#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int noOfEnclaves(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int> (m,0));

    for(int j = 0; j < m; j++)
    {
        if (not[0][j] == 'O')
        {
            vis[0][j] = 1;
            q.push({0,j});
        }
        if (not[n - 1][j] == 'O')
        {
            vis[n - 1][j] = 1;
            q.push({n-1, j});
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (not[i][0] == 'O')
        {
            vis[i][0] = 1;
            q.push({i,0});
        }
        if (not[i][m - 1] == 'O')
        {
            vis[i][m - 1] = 1;
            q.push({i, m-1});
        }
    }
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;

        q.pop();
        
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && not[nrow][ncol] == 'O')
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }

    int count = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                count++;
            }
        }
    }
    return count;
}