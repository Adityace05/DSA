// class Solution
// {
// public:
//     int perfectSum(vector<int> &arr, int target)
//     {
//         int w = target;
//         int n = arr.size();

//         vector<vector<int>> t(n + 1, vector<int>(w + 1, 0));

//         t[0][0] = 1;

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 0; j <= w; j++)
//             {
//                 if (arr[i - 1] <= j)
//                 {
//                     t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
//                 }
//                 else
//                 {
//                     t[i][j] = t[i - 1][j];
//                 }
//             }
//         }
//         return t[n][w];
//     }
// };