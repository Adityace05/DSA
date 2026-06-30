// class Solution
// {
// public:
//     int lastStoneWeightII(vector<int> &stones)
//     {
//         int n = stones.size();
//         int sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             sum += stones[i];
//         }
//         vector<vector<bool>> t(n + 1, vector<bool>(sum + 1, false));

//         for (int i = 0; i <= n; i++)
//         {
//             t[i][0] = true;
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= sum; j++)
//             {
//                 if (stones[i - 1] <= j)
//                 {
//                     t[i][j] = t[i - 1][j] || t[i - 1][j - stones[i - 1]];
//                 }
//                 else
//                 {
//                     t[i][j] = t[i - 1][j];
//                 }
//             }
//         }

//         vector<int> arr;

//         for (int i = 0; i <= sum / 2; i++)
//         {
//             if (t[n][i])
//             {
//                 arr.push_back(i);
//             }
//         }
//         return abs(2 * arr[arr.size() - 1] - sum);
//     }
// };