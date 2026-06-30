// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         if(grid[0][0] != 0 || grid[n-1][m-1] != 0){
//             return -1;
//         }

//         vector<vector<int>> dist(n, vector<int>(m, 1e9));
//         dist[0][0] = 1;

//         priority_queue<
//         pair<int, pair<int,int>>,
//         vector<pair<int, pair<int,int>>>,
//         greater<pair<int, pair<int,int>>>>
//         pq;
//         pq.push({1,{0,0}}); // {dis, node}
        
//         int delRow[] = {1,0,-1,0,1,-1,-1,1};
//         int delCol[] = {0,1,0,-1,1,-1,1,-1};

//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();
//             int dis = it.first;
//             int r = it.second.first;
//             int c = it.second.second;

//             for(int i=0; i<8; i++){
//                 int nrow = r + delRow[i];
//                 int ncol = c + delCol[i];

//                 if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] != 1 && dis + 1 < dist[nrow][ncol]){      dist[nrow][ncol] = dis + 1;
//                     pq.push({dis + 1 , {nrow, ncol}});
//                 }
//             }


//         }
//         if(dist[n-1][m-1] == 1e9){
//             return -1;
//         }
//         return dist[n-1][m-1];
//     }
// };