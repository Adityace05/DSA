//  User function template for C++

// class Solution {
//   public:
//     void floydWarshall(vector<vector<int>> &dist) {
//         int n = dist.size();
//         const int INF = 1e8;

//         // Step 1: Convert -1 to INF
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(dist[i][j] == -1){
//                     dist[i][j] = INF;
//                 }
//             }
//             dist[i][i] = 0;
//         }

//         // Step 2: Floyd-Warshall
//         for(int k = 0; k < n; k++){
//             for(int i = 0; i < n; i++){
//                 for(int j = 0; j < n; j++){
//                     if(dist[i][k] < INF && dist[k][j] < INF)
//                         dist[i][j] = min(dist[i][j],
//                                          dist[i][k] + dist[k][j]);
//                 }
//             }
//         }
        
//         // for negative cycle 
//         for(int i=0; i<n; i++){
//             if(dist[i][i] < 0){
//                 cout<< negative cycle;
//             }
//         }
//         // Step 3: Convert INF back to -1
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(dist[i][j] == INF){
//                     dist[i][j] = -1;
//                 }
//             }
//         }
//     }
// };
